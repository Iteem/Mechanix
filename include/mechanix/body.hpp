#ifndef BODY_HPP_INCLUDED
#define BODY_HPP_INCLUDED

#include <mechanix/bodydef.hpp>
#include <mechanix/shape.hpp>
#include <mechanix/vector2.hpp>

namespace mx
{

/**The body class
*/
class Body
{
    public:
        Body(const BodyDef &bodyDef, Shape *shape);

        ~Body();

        void update(float timeStep);

        const BodyDef& getBodyDef(void) const;

        Vector2f getVelocity(void) const;

        float getAngularVelocity(void) const;

        void acceleration(Vector2f vec);

        void angularAcceleration(float acc);

        void setShape(const Shape *shape);

        Shape *getShape(void) const;
    private:
        Vector2f m_velocity;
        float m_angularVelocity;

        Shape *m_shape;
        BodyDef m_bodyDef;
};

} //namespace mx

#endif // BODY_HPP_INCLUDED
