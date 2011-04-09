#include <mechanix/world.hpp>

namespace mx
{

World::World()
{
}

World::~World()
{
}

Body::Ptr World::createBody(const BodyDef &bodyDef, Shape *shape)
{
    Body::Ptr ptr(new Body(bodyDef, shape));
    m_bodies.push_back(ptr);
    return ptr;
}

} //namespace mx
