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

        float getMass(void) const;

        void setMomentOfInertia(float momentOfInertia);

        float getMomentOfInertia(void) const;

        void setFriction(float friction);

        float getFriction(void) const;

        void setElasticity(float elasticity);

        float getElasticity(void) const;

        void setStatic(bool b);

        bool isStatic(void) const;
    private:
        float m_mass;
        float m_momentOfInertia;
        float m_friction;
        float m_elasticity;

        bool m_isStatic;
};

} //namespace mx

#endif // BODYDEF_HPP_INCLUDED
