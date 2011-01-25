#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include <mechanix/vector2.hpp>

namespace mx
{

/** Utility class to manipulate lines
*/
class Line
{
    public:
        Line(Vector2f pointm = Vector2f(0, 0), Vector2f directionVector = Vector2f(0, 0));

        ~Line();

        void setPoint(const Vector2f &vec);

        Vector2f getPoint(void);

        void setDirectionVector(const Vector2f &point);

        Vector2f getDirectionVector(void);

        float intersects(const Line &line);

    private:
        Vector2f m_point;
        Vector2f m_directionVector;
};

} //namespace mx

#endif // LINE_HPP_INCLUDED
