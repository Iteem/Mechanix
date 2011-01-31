#ifndef MATRIX3_HPP_INCLUDED
#define MATRIX3_HPP_INCLUDED

#include <mechanix/vector2.hpp>

#include <cmath>

namespace mx
{

/** A simple matrix template class.
*/
template <typename T>
class Matrix3
{
    public:
        /** Default Constructor.
         * Creates an identity matrix.
         */
        Matrix3();

        /** Construct a matrix from its 9 elements.
        */
        Matrix3(T a11, T a12, T a13,
                T a21, T a22, T a23,
                T a31, T a32, T a33);

        /** Destructor.
         */
        ~Matrix3(){};

        /** Transform a point by the matrix.
        * @param point Point to transform
        * @return Transformed point
        */
        Vector2<T> transform(const Vector2<T>& point) const;

        /** Create a Matrix from a given translation,rotation and origin.
        * @param translation Tranlation
        * @param translation Origin
        * @param rotation Rotation angle in radian
        */
        void transformation(const Vector2<T>& translation, const Vector2<T>& origin, T rotation);

        /** Overload of binary * operator
        * @param rhs Right operand of the multiplication
        * @return The result of the multiplication
        */
        Matrix3<T> operator * (const Matrix3& rhs) const;
    private:
        T m_data[9];
};

#include <mechanix/matrix3.inl>

typedef Matrix3<int>   Matrix3i;
typedef Matrix3<float> Matrix3f;

} //namespace mx

#endif // MATRIX3_HPP_INCLUDED
