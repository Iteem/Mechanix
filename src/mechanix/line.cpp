#include <mechanix/line.hpp>
#include <cmath>

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
    //t1 = (u2*(y1-y2) - v2*(x1-x2))/(u1*v2 - u2*v1)
    float q = m_directionVector.x*line.m_directionVector.y - line.m_directionVector.x*m_directionVector.y;

    return (line.m_directionVector.x*(m_point.y - line.m_point.y) - line.m_directionVector.y*(m_point.x - line.m_point.x)) / q;
}

} //namespace mx
