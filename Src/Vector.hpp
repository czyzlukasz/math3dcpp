#ifndef MATH3DCPP_VECTOR_HPP
#define MATH3DCPP_VECTOR_HPP

#include <VectorImpl.hpp>


template<typename TYPE>
struct Vector3 : VectorImpl<3, TYPE>{
    Vector3();
    Vector3(TYPE x, TYPE y, TYPE z);
    Vector3(const VectorImpl<3, TYPE>& vector);

    TYPE& x();
    TYPE& y();
    TYPE& z();

    const TYPE& x() const;
    const TYPE& y() const;
    const TYPE& z() const;
};

template<typename TYPE>
struct Vector4 : VectorImpl<4, TYPE>{
    Vector4();
    Vector4(TYPE a, TYPE b, TYPE c, TYPE d);
    Vector4(const VectorImpl<4, TYPE>& vector);

    TYPE& a();
    TYPE& b();
    TYPE& c();
    TYPE& d();

    const TYPE& a() const;
    const TYPE& b() const;
    const TYPE& c() const;
    const TYPE& d() const;
};



#endif //MATH3DCPP_VECTOR_HPP
