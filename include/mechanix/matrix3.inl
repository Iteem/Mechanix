template <typename T>
Matrix3<T>::Matrix3()
{
    m_data[0] = 1; m_data[1] = 0; m_data[2] = 0;
    m_data[3] = 0; m_data[4] = 1; m_data[5] = 0;
    m_data[6] = 0; m_data[7] = 0; m_data[8] = 1;
}

template <typename T>
Matrix3<T>::Matrix3(T a11, T a12, T a13,
                    T a21, T a22, T a23,
                    T a31, T a32, T a33)
{
    m_data[0] = a11; m_data[1] = a12; m_data[2] = a13;
    m_data[3] = a21; m_data[4] = a22; m_data[5] = a23;
    m_data[6] = a31; m_data[7] = a32; m_data[8] = a33;
}

template <typename T>
Vector2<T> Matrix3<T>::transform(const Vector2<T>& point) const
{
    return Vector2<T>(m_data[0] * point.x + m_data[1] * point.y + m_data[2],
                      m_data[3] * point.x + m_data[4] * point.y + m_data[5]);
}

template <typename T>
void Matrix3<T>::transformation(const Vector2<T>& translation, T rotation)
{
    T sinx = std::sin(rotation);
    T cosx = std::cos(rotation);
    m_data[0] = cosx; m_data[1] =-sinx; m_data[2] = translation.x;
    m_data[3] = sinx; m_data[4] = cosx; m_data[5] = translation.y;
    m_data[6] = 0;    m_data[7] = 0;    m_data[8] = 1;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator * (const Matrix3& rhs) const
{
    return Matrix3<T>(m_data[0] * rhs.m_data[0] + m_data[1] * rhs.m_data[3] + m_data[2] * rhs.m_data[6],
                      m_data[3] * rhs.m_data[1] + m_data[4] * rhs.m_data[4] + m_data[5] * rhs.m_data[7],
                      m_data[6] * rhs.m_data[2] + m_data[7] * rhs.m_data[5] + m_data[8] * rhs.m_data[8]);
}
