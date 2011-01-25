#include <mechanix/line.hpp>

namespace mx
{

Line::Line(Vector2f point, Vector2f directionVector) :
m_point(point),
m_directionVector(directionVector)
{
}

Line::~Line()
{
}

void Line::setPoint(const Vector2f &point)
{
    m_point = point;
}

Vector2f Line::getPoint(void)
{
    return m_point;
}

void Line::setDirectionVector(const Vector2f &vec)
{
    m_directionVector = vec;
}

Vector2f Line::getDirectionVector(void)
{
    return m_directionVector;
}

float Line::intersects(const Line &line)
{
    float q = (line.m_directionVector.x * m_directionVector.y)/
              (line.m_directionVector.y * m_directionVector.x);

    return (((line.m_point.x - m_point.x) / m_directionVector.x) -
            (q * (line.m_point.y - m_point.y) / m_directionVector.y)) /
            (1.f - q);
}

} //namespace mx
