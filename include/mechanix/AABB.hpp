#ifndef AABB_HPP_INCLUDED
#define AABB_HPP_INCLUDED

#include <mechanix/vector2.hpp>

namespace mx
{

class AABB
{
    public:
        AABB();
        AABB(mx::Vector2f bottomLeft, mx::Vector2f rightUpper);
        ~AABB();

        bool intersects(const AABB &rhs);

        mx::Vector2f bottomLeftCorner;
        mx::Vector2f rightUpperCorner;
};


} //namespace mx

#endif // AABB_HPP_INCLUDED
