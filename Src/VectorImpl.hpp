#ifndef MATH3DCPP_VECTORIMPL_HPP
#define MATH3DCPP_VECTORIMPL_HPP

#include <optional>
#include <initializer_list>
#include <array>

template<unsigned int DIM, typename TYPE>
struct VectorImpl {
    VectorImpl();

    // Defined in .hpp to avoid mess with template specialization
    template<typename... T>
    VectorImpl(T... initialValues) : values{initialValues...}{};

    TYPE length() const;
    std::optional<VectorImpl<DIM, TYPE>> normalized() const;

    // Operators
    VectorImpl<DIM, TYPE> operator/(TYPE other) const;
    VectorImpl<DIM, TYPE> operator*(TYPE other) const;
    VectorImpl<DIM, TYPE> operator+(const VectorImpl<DIM, TYPE>& other) const;
    VectorImpl<DIM, TYPE> operator-(const VectorImpl<DIM, TYPE>& other) const;
    VectorImpl<DIM, TYPE> operator-() const;
    bool operator == (const VectorImpl<DIM, TYPE>& other) const;

    std::array<TYPE, DIM> values;
};


#endif //MATH3DCPP_VECTORIMPL_HPP
