#include <mechanix/AABB.hpp>
#include <algorithm>

namespace mx
{

AABB::AABB()
{
}

AABB::AABB(mx::Vector2f bottomLeft, mx::Vector2f rightUpper) :
bottomLeftCorner(bottomLeft),
rightUpperCorner(rightUpper)
{
}

AABB::~AABB()
{
}

bool AABB::intersects(const AABB &rhs)
{
    float left   = std::max(bottomLeftCorner.x, rhs.bottomLeftCorner.x);
    float right  = std::min(rightUpperCorner.x, rhs.rightUpperCorner.x);
    float up     = std::min(rightUpperCorner.y, rhs.rightUpperCorner.y);
    float bottom = std::max(bottomLeftCorner.y, rhs.bottomLeftCorner.y);

    if(left < right and bottom < up){
        return true;
    }
    return false;
}

} //namespace mx
