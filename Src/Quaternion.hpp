#ifndef MATH3DCPP_QUATERNION_HPP
#define MATH3DCPP_QUATERNION_HPP


template<typename TYPE>
struct Vector3;
template<unsigned int DIM, typename TYPE>
struct Matrix;

template<typename TYPE>
struct Quaternion {

    Quaternion(const Vector3<TYPE>& eulerAngles);
    Quaternion(TYPE w, TYPE x, TYPE y, TYPE z);

    Vector3<TYPE> toEulerAngles() const;
    TYPE length() const;
    Quaternion<TYPE> normalized() const;
    Quaternion<TYPE> reciprocated() const;
    Matrix<3, TYPE> toRotationMatrix() const;

    Quaternion<TYPE> operator*(const Quaternion<TYPE>& other) const;

    TYPE w;
    TYPE x;
    TYPE y;
    TYPE z;
};


#endif //MATH3DCPP_QUATERNION_HPP
