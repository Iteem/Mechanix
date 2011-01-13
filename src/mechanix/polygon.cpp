#include <mechanix/polygon.hpp>
#include <mechanix/matrix3.hpp>

#include <cmath>

namespace mx
{

Polygon::Polygon(size_t numberOfPoints)
{
    SetNumberOfPoints(numberOfPoints);
}

Polygon::~Polygon()
{
}

void Polygon::SetNumberOfPoints(size_t numberOfPoints)
{
    if(numberOfPoints < 3)
        numberOfPoints = 3;
    m_points.resize(numberOfPoints);
    m_transformedPoints.resize(numberOfPoints);
    m_normals.resize(numberOfPoints);
    m_transformedNormals.resize(numberOfPoints);
}

size_t Polygon::GetNumberOfPoint(void)
{
    return m_points.size();
}

Vector2f Polygon::getPoint(size_t i) const
{
    return m_points[i];
}

void Polygon::setPoint(size_t i, Vector2f position)
{
    m_points[i] = position;

    Vector2f tmp = m_points[i];
    if(i == m_points.size()-1)
        tmp -= m_points[0];
    else
        tmp -= m_points[i+1];
    tmp = tmp.normal();
    tmp.normalize();
    m_normals[i] = tmp;

    m_isCompiled = false;
}

bool Polygon::collide(const Shape *shape) const
{
    const Polygon *polygon = static_cast<const Polygon *>(shape);
    if(!m_isCompiled)
        compile();
    if(!polygon->m_isCompiled)
        polygon->compile();
    return inter_collide(polygon) and polygon->inter_collide(this);
}

void Polygon::compile(void) const
{
    Matrix3f tmp;
    tmp.transformation(Vector2f(0,0), getRotation());
    for(size_t i = 0; i < m_normals.size(); ++i){
        m_transformedNormals[i] = tmp.transform(m_normals[i]);
    }

    tmp.transformation(getPosition() - getOrigin(), getRotation());
    for(size_t i = 0; i < m_points.size(); ++i){
        m_transformedPoints[i] = tmp.transform(m_points[i]);
    }

    m_isCompiled = true;
}

bool Polygon::inter_collide(const Polygon *polygon) const
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

} //namespace mx
