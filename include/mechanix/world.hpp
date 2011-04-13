#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <mechanix/body.hpp>
#include <mechanix/vector2.hpp>

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

        void update(float timeStep);

        void setGravitation(const mx::Vector2f &gravitation);

        mx::Vector2f getGravitation(void);
    private:
        typedef std::list<Body::Ptr> BodyList;
        BodyList m_bodies;

        mx::Vector2f m_gravitation;
};

} //namespace mx

#endif // WORLD_HPP_INCLUDED
