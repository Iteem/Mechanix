#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#include <mechanix/vector2.hpp>

#include <vector>

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
        void SetPosition(const Vector2f &position);

        /** Get the position of the shape
         * @return positon of the shape
         */
        Vector2f GetPosition(void);

        /** Set the origin(center) of the shape.
         * @param origin new origin
         */
        void SetOrigin(const Vector2f &origin);

        /** Get the origin(center) of the shape
         * @return origin of the shape
         */
        Vector2f GetOrigin(void);

        /** Set the rotation of the shape.
         * @param new rotation in radians
         */
        void SetRotation(float rotation);

        /** Get the rotation of the shape.
         * @return rotation of the shape in radians
         */
        float GetRotation(void);

    private:
        Vector2f m_position; /**< Position of the shape*/
        Vector2f m_origin;   /**< Origin of the shape*/
        float    m_rotation; /**< Rotation of the shape*/

};

} //namespace mx

#endif // SHAPE_HPP_INCLUDED
