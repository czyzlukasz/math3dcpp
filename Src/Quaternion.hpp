#ifndef MATH3DCPP_QUATERNION_HPP
#define MATH3DCPP_QUATERNION_HPP

template<typename TYPE>
struct Vector3;

template<typename TYPE>
struct Quaternion {

    Quaternion(const Vector3<TYPE>& eulerAngles);
    Vector3<TYPE> toEulerAngles() const;

    TYPE w;
    TYPE x;
    TYPE y;
    TYPE z;
};


#endif //MATH3DCPP_QUATERNION_HPP
