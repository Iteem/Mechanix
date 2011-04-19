#include <mechanix/bodydef.hpp>

namespace mx
{

BodyDef::BodyDef() :
m_mass(1),
m_momentOfInertia(1),
m_friction(0),
m_elasticity(0),
m_isStatic(false)
{
}

BodyDef::~BodyDef()
{
}

void BodyDef::setMass(float mass)
{
    m_mass = mass;
}

float BodyDef::getMass(void) const
{
    return m_mass;
}

void BodyDef::setMomentOfInertia(float momentOfInertia)
{
    m_momentOfInertia = momentOfInertia;
}

float BodyDef::getMomentOfInertia(void) const
{
    return m_momentOfInertia;
}

void BodyDef::setFriction(float friction)
{
    m_friction = friction;
}

float BodyDef::getFriction(void) const
{
    return m_friction;
}

void BodyDef::setElasticity(float elasticity)
{
    m_elasticity = elasticity;
}

float BodyDef::getElasticity(void) const
{
    return m_elasticity;
}

void BodyDef::setStatic(bool b)
{
    m_isStatic = b;
}

bool BodyDef::isStatic(void) const
{
    return m_isStatic;
}

} //namespace mx
