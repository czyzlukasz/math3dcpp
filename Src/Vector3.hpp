#ifndef MATH3DCPP_VECTOR3_HPP
#define MATH3DCPP_VECTOR3_HPP

#include <optional>


template<typename TYPE>
struct Vector3Impl {
    using Vector3 = Vector3Impl<TYPE>;
    Vector3Impl();
    Vector3Impl(TYPE x, TYPE y, TYPE z);

    TYPE length() const;
    std::optional<Vector3> normalized() const;

    // Operators
    Vector3 operator/(TYPE other) const;
    Vector3 operator*(TYPE other) const;
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator-() const;
    bool operator == (const Vector3& other) const;

    TYPE x;
    TYPE y;
    TYPE z;
};


#endif //MATH3DCPP_VECTOR3_HPP
