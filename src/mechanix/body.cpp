#include <mechanix/body.hpp>
#include <mechanix/polygon.hpp>

namespace mx
{

Body::Body(const BodyDef &bodyDef, const Shape *shape) :
m_velocity(),
m_angularVelocity(0.f),
m_shape(),
m_bodyDef(bodyDef)
{
    setShape(shape);
}

Body::~Body()
{
}

void Body::update(float timeStep)
{
    m_shape->setPosition(m_shape->getPosition() + m_velocity * timeStep);
    m_shape->setRotation(m_shape->getRotation() + m_angularVelocity * timeStep);
}

const BodyDef& Body::getBodyDef(void) const
{
    return m_bodyDef;
}

Vector2f Body::getVelocity(void) const
{
    return m_velocity;
}

float Body::getAngularVelocity(void) const
{
    return m_angularVelocity;
}

void Body::acceleration(Vector2f vec)
{
    m_velocity += vec;
}

void Body::angularAcceleration(float acc)
{
    m_angularVelocity += acc;
}

void Body::setShape(const Shape *shape)
{
    if(shape->getType() == Shape::PolygonType){
        m_shape = Shape::Ptr(new Polygon(*static_cast<const Polygon*>(shape)));
    }else{
        //TODO
    }
}

Shape::Ptr Body::getShape(void) const
{
    return m_shape;
}

} //namespace mx
