#ifndef POLYGON_HPP_INCLUDED
#define POLYGON_HPP_INCLUDED

#include <mechanix/vector2.hpp>
#include <mechanix/shape.hpp>

#include <cstddef>
#include <vector>

namespace mx
{

/**Class for convex polygons.
*/
class Polygon :  Shape
{
    public:
        Polygon(size_t numberOfPoints = 0);

        virtual ~Polygon();

        void SetNumberOfPoints(size_t numberOfPoints);

        size_t GetNumberOfPoint(void);

        const Vector2f& operator[](size_t i) const;

        Vector2f& operator[](size_t i);

    private:
        std::vector< Vector2f > m_points;
};

} //namespace mx

#endif // POLYGON_HPP_INCLUDED
