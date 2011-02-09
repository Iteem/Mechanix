#include <mechanix/bodydef.hpp>

namespace mx
{

BodyDef::BodyDef() :
m_mass(0),
m_momentOfInertia(0),
m_friction(0),
m_elasticity(0)
{
}

BodyDef::~BodyDef()
{
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

} //namespace mx
