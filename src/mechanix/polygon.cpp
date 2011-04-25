#include <mechanix/polygon.hpp>
#include <mechanix/matrix3.hpp>

#include <algorithm>
#include <cmath>

namespace mx
{

Polygon::Polygon(size_t numberOfPoints)
{
    setNumberOfPoints(numberOfPoints);
}

Polygon::~Polygon()
{
}

void Polygon::setNumberOfPoints(size_t numberOfPoints)
{
    if(numberOfPoints < 3)
        numberOfPoints = 3;
    m_points.resize(numberOfPoints);
    m_transformedPoints.resize(numberOfPoints);
    m_normals.resize(numberOfPoints);
    m_transformedNormals.resize(numberOfPoints);

    m_isCompiled = false;
}

size_t Polygon::getNumberOfPoints(void)
{
    return m_points.size();
}

Vector2f Polygon::getTransformedPoint(size_t i) const
{
    if(!m_isCompiled)
        compile();

    return m_transformedPoints[i];
}

Vector2f Polygon::getPoint(size_t i) const
{
    return m_points[i];
}

void Polygon::setPoint(size_t i, Vector2f position)
{
    m_points[i] = position;

    int j = i - 1;
    if(j < 0) j = m_points.size()-1;
    int k = i + 1;
    if(k >= static_cast<int>(m_points.size())) k = 0;

    Vector2f tmp = (m_points[j]-m_points[i]).normal();
    tmp.normalize();
    m_normals[j] = tmp;
    tmp = (m_points[i]-m_points[k]).normal();
    tmp.normalize();
    m_normals[i] = tmp;


    m_isCompiled = false;
}

AABB Polygon::getAABB(void) const
{
    if(!m_isCompiled)
        compile();

    if(m_points.size() > 0){
        float left   = m_transformedPoints[0].x;
        float right  = m_transformedPoints[0].x;
        float top    = m_transformedPoints[0].y;
        float bottom = m_transformedPoints[0].y;
        for(size_t i = 1; i < m_points.size(); ++i){
            left   = std::min(m_transformedPoints[i].x, left);
            right  = std::max(m_transformedPoints[i].x, right);
            top    = std::max(m_transformedPoints[i].y, top);
            bottom = std::min(m_transformedPoints[i].y, bottom);
        }
        return AABB(mx::Vector2f(left, bottom), mx::Vector2f(right, top));
    }else{
        return AABB();
    }
}

Shape::Type Polygon::getType() const
{
    return Shape::PolygonType;
}

bool Polygon::collide(const Shape *shape) const
{
    switch(shape->getType())
    {
        case PolygonType:
            {
            const Polygon *polygon = static_cast<const Polygon *>(shape);
            if(!m_isCompiled)
                compile();
            if(!polygon->m_isCompiled)
                polygon->compile();
            return interCollide(polygon) and polygon->interCollide(this);
            }
        default:
            return false;
    }
}

void Polygon::compile(void) const
{
    Matrix3f tmp;
    tmp.transformation(Vector2f(0,0), Vector2f(0,0), getRotation());
    if(m_normals.size() != m_transformedNormals.size())
        m_transformedNormals.resize(m_normals.size());
    for(size_t i = 0; i < m_normals.size(); ++i){
        m_transformedNormals[i] = tmp.transform(m_normals[i]);
    }

    tmp.transformation(getPosition(), getOrigin(), getRotation());
    if(m_points.size() != m_transformedPoints.size())
        m_transformedPoints.resize(m_points.size());
    for(size_t i = 0; i < m_points.size(); ++i){
        m_transformedPoints[i] = tmp.transform(m_points[i]);
    }

    m_isCompiled = true;
}

bool Polygon::interCollide(const Polygon *polygon) const
{
    for(size_t i = 0; i < m_transformedNormals.size(); ++i){
        float min1 = dot(m_transformedNormals[i], m_transformedPoints[0]);
        float max1 = min1;
        float min2 = dot(m_transformedNormals[i], polygon->m_transformedPoints[0]);
        float max2 = min2;

        for(size_t j = 0; j < m_transformedPoints.size(); ++j){
            float h = dot(m_transformedNormals[i], m_transformedPoints[j]);
            if(h < min1) min1 = h;
            else if(h > max1) max1 = h;
        }

        for(size_t j = 0; j < polygon->m_transformedPoints.size(); ++j){
            float h = dot(m_transformedNormals[i], polygon->m_transformedPoints[j]);
            if(h < min2) min2 = h;
            else if(h > max2) max2 = h;
        }

        if(max1 < min2 or max2 < min1)
            return false;
    }
    return true;
}

Vector2f Polygon::MTD(const Shape *shape) const
{
    switch(shape->getType())
    {
        case PolygonType:
            {
            const Polygon *polygon = static_cast<const Polygon *>(shape);
            Vector2f vec;
            Vector2f vec1 = internMTD(polygon);
            Vector2f vec2 = polygon->internMTD(this);

            if(vec1.length() < vec2.length())
                vec = vec1;
            else
                vec = vec2;

            if(dot(vec, polygon->getPosition()-getPosition()) < 0)
                return vec;
            else
                return -vec;
            }
            break;
        default:
            return mx::Vector2f(0, 0);
            break;
    }
}

Vector2f Polygon::internMTD(const Polygon *polygon) const
{
    Vector2f vec;
    bool firstIteration = true;
    for(size_t i = 0; i < m_transformedNormals.size(); ++i){
        float min1 = dot(m_transformedNormals[i], m_transformedPoints[0]);
        float max1 = min1;
        float min2 = dot(m_transformedNormals[i], polygon->m_transformedPoints[0]);
        float max2 = min2;

        for(size_t j = 0; j < m_transformedPoints.size(); ++j){
            float h = dot(m_transformedNormals[i], m_transformedPoints[j]);
            if(h < min1) min1 = h;
            else if(h > max1) max1 = h;
        }

        for(size_t j = 0; j < polygon->m_transformedPoints.size(); ++j){
            float h = dot(m_transformedNormals[i], polygon->m_transformedPoints[j]);
            if(h < min2) min2 = h;
            else if(h > max2) max2 = h;
        }

        float k1 = max1 - min2;
        float k2 = max2 - min1;

        Vector2f tmp;
        if(std::abs(k1) < std::abs(k2))
            tmp = m_transformedNormals[i] * k1;
        else
            tmp = m_transformedNormals[i] * k2;

        if(firstIteration){
            vec = tmp;
            firstIteration = false;
        }
        if(tmp.x*tmp.x + tmp.y*tmp.y < vec.x*vec.x + vec.y*vec.y)
            vec = tmp;
    }
    return vec;
}

} //namespace mx
