#include <mechanix/polygon.hpp>

namespace mx
{

Polygon::Polygon(size_t numberOfPoints) :
m_points(numberOfPoints)
{
}

Polygon::~Polygon()
{
}

void Polygon::SetNumberOfPoints(size_t numberOfPoints)
{
    m_points.resize(numberOfPoints);
}

size_t Polygon::GetNumberOfPoint(void)
{
    return m_points.size();
}

const Vector2f& Polygon::operator[](size_t i) const
{
    return m_points[i];
}

Vector2f& Polygon::operator[](size_t i)
{
    return m_points[i];
}

} //namespace mx
