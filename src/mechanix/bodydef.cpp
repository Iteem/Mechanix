#include <mechanix/bodydef.hpp>
#include <mechanix/polygon.hpp>

namespace mx
{

BodyDef::BodyDef() :
m_mass(0),
m_momentOfInertia(0),
m_friction(0),
m_elasticity(0),
m_shape(NULL)
{
}

BodyDef::~BodyDef()
{
    delete m_shape;
}

void BodyDef::setMass(float mass)
{
    m_mass = mass;
}

void BodyDef::setMomentOfInertia(float momentOfInertia)
{
    m_momentOfInertia = momentOfInertia;
}

void BodyDef::setFriction(float friction)
{
    m_friction = friction;
}

void BodyDef::setElasticity(float elasticity)
{
    m_elasticity = elasticity;
}

void BodyDef::setShape(const Shape * shape)
{
    delete m_shape;
    if(shape->getType() == Shape::PolygonType){
        m_shape = new Polygon(*(static_cast<const Polygon *>(shape)));
    }else{
    }
}

} //namespace mx
