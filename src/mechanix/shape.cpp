#include <mechanix/shape.hpp>

namespace mx
{

Shape::Shape() :
m_isCompiled(true),
m_position(0, 0),
m_origin(0,0),
m_rotation(0)
{
}

Shape::~Shape()
{
}

void Shape::setPosition(const Vector2f &position)
{
    m_position = position;
    m_isCompiled = false;
}

Vector2f Shape::getPosition(void) const
{
    return m_position;
}

void Shape::setOrigin(const Vector2f &origin)
{
    m_origin = origin;
    m_isCompiled = false;
}

Vector2f Shape::getOrigin(void) const
{
    return m_origin;
}

void Shape::setRotation(float rotation)
{
    m_rotation = rotation;
    m_isCompiled = false;
}

float Shape::getRotation(void) const
{
    return m_rotation;
}

} //namespace mx
