#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <mechanix/body.hpp>

#include <list>

namespace mx
{

/**World class, managing all bodys.
*/

class World
{
    public:
        World();

        ~World();

        Body::Ptr createBody(const BodyDef &bodyDef, const Shape *shape);
    private:
        typedef std::list<Body::Ptr> BodyList;

        BodyList m_bodies;
};

} //namespace mx

#endif // WORLD_HPP_INCLUDED
