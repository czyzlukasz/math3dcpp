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



#endif //MATH3DCPP_VECTOR_HPP
