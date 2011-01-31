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
class Polygon : public Shape
{
    public:
        Polygon(size_t numberOfPoints = 0);

        virtual ~Polygon();

        void setNumberOfPoints(size_t numberOfPoints);

        size_t getNumberOfPoints(void);

        void setPoint(size_t i, Vector2f position);

        Vector2f getPoint(size_t i) const;

        Vector2f getTransformedPoint(size_t i) const;

        virtual bool collide(const Shape *shape) const;

        Vector2f MTD(const Polygon *polygon) const;

        virtual Type getType() const;

    private:
        void compile(void) const;
        bool interCollide(const Polygon *polygon) const;
        Vector2f internMTD(const Polygon *polygon) const;

        std::vector< Vector2f > m_points;
        mutable std::vector< Vector2f > m_transformedPoints;
        std::vector< Vector2f > m_normals;
        mutable std::vector< Vector2f > m_transformedNormals;
};

} //namespace mx

#endif // POLYGON_HPP_INCLUDED
