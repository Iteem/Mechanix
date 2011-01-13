template <typename T>
inline Vector2<T>::Vector2() :
x(0),
y(0)
{
}

template <typename T>
inline Vector2<T>::Vector2(T X, T Y) :
x(X),
y(Y)
{
}

template <typename T>
inline T Vector2<T>::length() const
{
    return std::sqrt(x*x + y*y);
}

template <typename T>
inline void Vector2<T>::normalize()
{
    T tmp = length();
    *this /= tmp;
}

template <typename T>
inline Vector2<T> Vector2<T>::normal() const
{
    return Vector2<T>(-y, x);
}

template <typename T>
inline T dot(const Vector2<T> &lhs, const Vector2<T> &rhs)
{
    return lhs.x*rhs.x + lhs.y*rhs.y;
}

template <typename T>
inline T cross(const Vector2<T> &lhs, const Vector2<T> &rhs)
{
    return lhs.x*rhs.y - lhs.y*rhs.x;
}

template <typename T>
inline Vector2<T> operator -(const Vector2<T> &vec)
{
    return Vector2<T>(-vec.x, -vec.y);
}

template <typename T>
inline Vector2<T>& operator +=(Vector2<T> &lhs, const Vector2<T> &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

template <typename T>
inline Vector2<T>& operator -=(Vector2<T>& lhs, const Vector2<T>& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

template <typename T>
inline Vector2<T> operator +(const Vector2<T> &lhs, const Vector2<T> &rhs)
{
    return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template <typename T>
inline Vector2<T> operator -(const Vector2<T> &lhs, const Vector2<T> &rhs)
{
    return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template <typename T>
inline Vector2<T> operator *(const Vector2<T> &lhs, T rhs)
{
    return Vector2<T>(lhs.x * rhs, lhs.y * rhs);
}

template <typename T>
inline Vector2<T> operator *(T lhs, const Vector2<T> &rhs)
{
    return Vector2<T>(lhs * rhs.x, lhs * rhs.y);
}

template <typename T>
inline Vector2<T>& operator *=(Vector2<T> &lhs, T rhs)
{
    lhs.x *= rhs;
    lhs.y *= lhs;
    return lhs;
}

template <typename T>
inline Vector2<T> operator /(const Vector2<T> &lhs, T rhs)
{
    return Vector2<T>(lhs.x / rhs, lhs.y / rhs);
}

template <typename T>
inline Vector2<T>& operator /=(Vector2<T> &lhs, T rhs)
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}

template <typename T>
inline bool operator ==(const Vector2<T> &lhs, const Vector2<T> &rhs)
{
    return lhs.x == rhs.x and lhs.y == rhs.y;
}

template <typename T>
inline bool operator !=(const Vector2<T> &lhs, const Vector2<T> &rhs)
{
    return lhs.x != rhs.x and lhs.y != rhs.y;
}
