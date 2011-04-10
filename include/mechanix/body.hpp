#ifndef BODY_HPP_INCLUDED
#define BODY_HPP_INCLUDED

#include <mechanix/bodydef.hpp>
#include <mechanix/shape.hpp>
#include <mechanix/vector2.hpp>

#include <boost/shared_ptr.hpp>

namespace mx
{

/**The body class
*/
class Body
{
    public:
        Body(const BodyDef &bodyDef, const Shape *shape);

        ~Body();

        void update(float timeStep);

        const BodyDef& getBodyDef(void) const;

        Vector2f getVelocity(void) const;

        float getAngularVelocity(void) const;

        void acceleration(Vector2f vec);

        void angularAcceleration(float acc);

        void setShape(const Shape *shape);

        Shape::Ptr getShape(void) const;

        typedef boost::shared_ptr<Body> Ptr;
    private:
        Vector2f m_velocity;
        float m_angularVelocity;

        Shape::Ptr m_shape;
        BodyDef m_bodyDef;
};

} //namespace mx

#endif // BODY_HPP_INCLUDED
