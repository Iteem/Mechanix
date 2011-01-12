#ifndef Vector2_HPP_INCLUDED
#define Vector2_HPP_INCLUDED

#include <cmath>

namespace mx
{

/** A 2-dimensional vector template class.
*/
template <typename T>
class Vector2
{
    public:
        /** Default Constructor.
         * Creates a Vector2(0, 0).
         */
        Vector2();

        /** Construct the vector from its coordinates.
        * @param X X coordinate
        * @param Y Y coordinate
        */
        Vector2(T X, T Y);

        /** Destructor.
         */
        ~Vector2(){};

        /** Get the lenght of the vector.
        * @return lenght of the vector
        */
        T length() const;

        /** Normalize the vector.
        * Normalize the vector so its lenght is 1.
        */
        void normalize();

        /** Get the normal of the vector.
        * Please note that the normal is not automatically normalized.
        * @return the normal of the vector
        */
        Vector2<T> normal() const;

        T x; /**< X coordinate of the vector*/
        T y; /**< Y coordinate of the vector*/
};

/** @relates Vector2
  * Function to caluclate the dot product.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return Dot product of the two vectors
  */
template <typename T>
T dot(const Vector2<T> &lhs, const Vector2<T> &rhs);

/** @relates Vector2
  * Function to caluclate the cross product.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return Cross product of the two vectors
  */
template <typename T>
T cross(const Vector2<T> &lhs, const Vector2<T> &rhs);

/** @relates Vector2
  * Overload of the unary - operator.
  * @param vec Vector to negate
  * @return Memberwise negated vector
  */
template <typename T>
Vector2<T> operator -(const Vector2<T> &vec);

/** @relates Vector2
  * Overload of the binary += operator.
  * This operator performs a addition of both vectors,
  * and assigns the result to @a lhs.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return Reference to @a lhs
  */
template <typename T>
Vector2<T>& operator +=(Vector2<T> &lhs, const Vector2<T> &rhs);

/** @relates Vector2
  * Overload of the binary -= operator.
  * This operator performs a subtraction of both vectors,
  * and assigns the result to @a lhs.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return Reference to @a lhs
  */
template <typename T>
Vector2<T>& operator -=(Vector2<T>& lhs, const Vector2<T>& rhs);

/** @relates Vector2
  * Overload of the binary + operator.
  * This operator performs a memberwise addioton of both vectors.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return Memberwise addioton of both vectors
  */
template <typename T>
Vector2<T> operator +(const Vector2<T> &lhs, const Vector2<T> &rhs);

/** @relates Vector2
  * Overload of the binary - operator.
  * This operator performs a memberwise subtraction of both vectors.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return Memberwise subtraction of both vectors
  */
template <typename T>
Vector2<T> operator -(const Vector2<T> &lhs, const Vector2<T> &rhs);

/** @relates Vector2
  * Overload of the binary * operator.
  * This operator performs a multiplation of the vector
  * with the scalar.
  * @param lhs Vector
  * @param rhs Scalar
  * @return Memberwise multiplication of @a lhs by @a rhs
  */
template <typename T>
Vector2<T> operator *(const Vector2<T> &lhs, T rhs);

/** @relates Vector2
  * Overload of the binary * operator.
  * This operator performs a multiplation of the vector
  * with the scalar.
  * @param lhs Scalar
  * @param rhs Vector
  * @return Memberwise multiplication of @a rhs by @a lhs
  */
template <typename T>
Vector2<T> operator *(T lhs, const Vector2<T> &rhs);

/** @relates Vector2
  * Overload of the binary *= operator.
  * This operator performs a multiplation of the vector
  * with the scalar and assigns the result to @a lhs.
  * @param lhs Vector
  * @param rhs Scalar
  * @return Refernce to @a lhs
  */
template <typename T>
Vector2<T>& operator *=(Vector2<T> &lhs, T rhs);

/** @relates Vector2
  * Overload of the binary / operator.
  * This operator performs a division of the vector
  * with the scalar.
  * @param lhs Vector
  * @param rhs Scalar
  * @return Memberwise division of @a lhs by @a rhs
  */
template <typename T>
Vector2<T> operator /(const Vector2<T> &lhs, T rhs);

/** @relates Vector2
  * Overload of the binary /= operator.
  * This operator performs a division of the vector
  * with the scalar and assigns the result to @a lhs.
  * @param lhs Vector
  * @param rhs Scalar
  * @return Refernce to @a lhs
  */
template <typename T>
Vector2<T>& operator /=(Vector2<T> &lhs, T rhs);

/** @relates Vector2
  * Overload of the binary == operator.
  * This operator compares strict equality between two vectors.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return True if both vectors are equal
  */
template <typename T>
bool operator ==(const Vector2<T> &lhs, const Vector2<T> &rhs);

/** @relates Vector2
  * Overload of the binary != operator.
  * This operator compares strict inequality between two vectors.
  * @param lhs Left vector
  * @param rhs Right vector
  * @return True if both vectors are not equal
  */
template <typename T>
bool operator !=(const Vector2<T> &lhs, const Vector2<T> &rhs);

#include <mechanix/vector2.inl>

typedef Vector2<int>   Vector2i;
typedef Vector2<float> Vector2f;

} //namespace mx

#endif // VECTOR_HPP_INCLUDED
