#include <Vector3.hpp>
#include <cmath>

template struct Vector3Impl<double>;
template struct Vector3Impl<float>;

template<typename TYPE>
Vector3Impl<TYPE>::Vector3Impl() : x(), y(), z(){

}

template<typename TYPE>
Vector3Impl<TYPE>::Vector3Impl(TYPE x, TYPE y, TYPE z) : x(x), y(y), z(z){

}

template<typename TYPE>
TYPE Vector3Impl<TYPE>::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

template<typename TYPE>
std::optional<Vector3Impl<TYPE>> Vector3Impl<TYPE>::normalized() const {
    if(const TYPE det = length()){
        return *this / det;
    }
    return std::nullopt;
}

template<typename TYPE>
Vector3Impl<TYPE> Vector3Impl<TYPE>::operator/(TYPE other) const {
    return Vector3Impl<TYPE>(x / other, y / other, z / other);
}

template<typename TYPE>
Vector3Impl<TYPE> Vector3Impl<TYPE>::operator*(TYPE other) const {
    return Vector3Impl<TYPE>(x * other, y * other, z * other);
}

template<typename TYPE>
Vector3Impl<TYPE> Vector3Impl<TYPE>::operator+(const Vector3Impl<TYPE>& other) const{
    return Vector3Impl<TYPE>(x + other.x, y + other.y, z + other.z);
}

template<typename TYPE>
Vector3Impl<TYPE> Vector3Impl<TYPE>::operator-(const Vector3Impl<TYPE>& other) const{
    return Vector3Impl<TYPE>(x - other.x, y - other.y, z - other.z);
}

template<typename TYPE>
Vector3Impl<TYPE> Vector3Impl<TYPE>::operator-() const {
    return Vector3Impl<TYPE>(-x, -y, -z);
}

template<typename TYPE>
bool Vector3Impl<TYPE>::operator==(const Vector3Impl<TYPE>& other) const {
    return x == other.x && y == other.y && z == other.z;
}
