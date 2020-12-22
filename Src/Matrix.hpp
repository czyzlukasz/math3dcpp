#ifndef MATH3DCPP_MATRIX_HPP
#define MATH3DCPP_MATRIX_HPP

#include <array>

template<unsigned int DIM, typename TYPE>
struct Matrix {
    using ValueType = std::array<std::array<TYPE, DIM>, DIM>;

    Matrix();
    Matrix(ValueType&& value);
    Matrix(std::initializer_list<std::initializer_list<TYPE>>&& value);

    TYPE determinant() const;

    // Operators
    Matrix<DIM, TYPE> operator*(const Matrix<DIM, TYPE>& other) const;
    Matrix<DIM, TYPE> operator*(TYPE other) const;
    Matrix<DIM, TYPE> operator+(const Matrix<DIM, TYPE>& other) const;
    Matrix<DIM, TYPE> operator-(const Matrix<DIM, TYPE>& other) const;
    bool operator==(const Matrix<DIM, TYPE>& other) const;

    // Indexing is done by values[row][column]
    ValueType values;
};


#endif //MATH3DCPP_MATRIX_HPP
