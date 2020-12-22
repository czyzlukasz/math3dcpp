#ifndef MATH3DCPP_QUATERNION_HPP
#define MATH3DCPP_QUATERNION_HPP

template<typename TYPE>
struct Vector3Impl;

template<typename TYPE>
struct Quaternion {

    Quaternion(const Vector3Impl<TYPE>& eulerAngles);
    Vector3Impl<TYPE> toEulerAngles() const;

    TYPE w;
    TYPE x;
    TYPE y;
    TYPE z;
};


#endif //MATH3DCPP_QUATERNION_HPP
