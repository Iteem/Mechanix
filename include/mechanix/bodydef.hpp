#ifndef BODYDEF_HPP_INCLUDED
#define BODYDEF_HPP_INCLUDED

#include <mechanix/vector2.hpp>

namespace mx
{

/**A "template" for body creations.
*/

class BodyDef
{
    public:
        BodyDef();

        ~BodyDef();

        void setMass(float mass);

        void setMomentOfInertia(float momentOfInertia);

        void setFriction(float friction);

        void setElasticity(float elasticity);
    private:
        float m_mass;
        float m_momentOfInertia;
        float m_friction;
        float m_elasticity;
};

} //namespace mx

#endif // BODYDEF_HPP_INCLUDED
