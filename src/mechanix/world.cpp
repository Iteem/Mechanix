#include <mechanix/world.hpp>

namespace mx
{

World::World()
{
}

World::~World()
{
}

Body::Ptr World::createBody(const BodyDef &bodyDef, const Shape *shape)
{
    Body::Ptr ptr(new Body(bodyDef, shape));
    m_bodies.push_back(ptr);
    return ptr;
}


void World::update(float timeStep)
{
    for(BodyList::iterator it = m_bodies.begin(); it != m_bodies.end(); ++it){
        (*it)->update(timeStep);
    }
}

void World::setGravitation(const mx::Vector2f &gravitation)
{
    m_gravitation = gravitation;
}

mx::Vector2f World::getGravitation(void)
{
    return m_gravitation;
}

} //namespace mx
