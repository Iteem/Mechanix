#include <mechanix/shape.hpp>

namespace mx
{

Shape::Shape() :
m_position(0, 0),
m_origin(0,0),
m_rotation(0)
{
}

Shape::~Shape()
{
}

void Shape::SetPosition(const Vector2f &position)
{
    m_position = position;
}

Vector2f Shape::GetPosition(void)
{
    return m_position;
}

void Shape::SetOrigin(const Vector2f &origin)
{
    m_origin = origin;
}

Vector2f Shape::GetOrigin(void)
{
    return m_origin;
}

void Shape::SetRotation(float rotation)
{
    m_rotation = rotation;
}

float Shape::GetRotation(void)
{
    return m_rotation;
}

} //namespace mx
