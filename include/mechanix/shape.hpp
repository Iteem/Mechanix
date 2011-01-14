#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#include <mechanix/vector2.hpp>

namespace mx
{

/**Abstract base class for shapes.
*/
class Shape
{
    public:
        /** Default Constructor.
         * Creates a empty shape.
         */
        Shape();

        /** Virtual destructor.
         */
        virtual ~Shape();

        /** Set the position of the shape.
         * @param position new position
         */
        void setPosition(const Vector2f &position);

        /** Get the position of the shape
         * @return positon of the shape
         */
        Vector2f getPosition(void) const;

        /** Set the origin(center) of the shape.
         * @param origin new origin
         */
        void setOrigin(const Vector2f &origin);

        /** Get the origin(center) of the shape
         * @return origin of the shape
         */
        Vector2f getOrigin(void) const;

        /** Set the rotation of the shape.
         * @param rotation new rotation in radians
         */
        void setRotation(float rotation);

        /** Get the rotation of the shape.
         * @return rotation of the shape in radians
         */
        float getRotation(void) const;

        /** Check if the shape collide with an other.
         * @return true if the two shapes collide
         */
        virtual bool collide(const Shape *shape) const = 0;

        enum Type{
            PolygonType,
            CircleType,
            LineType,
            NoneType
        };

        virtual Type getType(void) const = 0;

    protected:
        mutable bool m_isCompiled;

    private:
        Vector2f m_position; /**< Position of the shape*/
        Vector2f m_origin;   /**< Origin of the shape*/
        float    m_rotation; /**< Rotation of the shape*/

};

} //namespace mx

#endif // SHAPE_HPP_INCLUDED
