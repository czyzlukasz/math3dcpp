#include <Vector.hpp>

template struct Vector3<double>;
template struct Vector3<float>;

template<typename TYPE>
Vector3<TYPE>::Vector3() : VectorImpl<3, TYPE>(){

}

template<typename TYPE>
Vector3<TYPE>::Vector3(TYPE x, TYPE y, TYPE z) : VectorImpl<3, TYPE>({x, y, z}){

}

template<typename TYPE>
Vector3<TYPE>::Vector3(const VectorImpl<3, TYPE>& vector) : VectorImpl<3, TYPE>(vector){

}

template<typename TYPE>
TYPE& Vector3<TYPE>::x() {
    return this->values[0];
}

template<typename TYPE>
TYPE& Vector3<TYPE>::y() {
    return this->values[1];
}

template<typename TYPE>
TYPE& Vector3<TYPE>::z() {
    return this->values[2];
}

template<typename TYPE>
const TYPE& Vector3<TYPE>::x() const{
    return this->values[0];
}

template<typename TYPE>
const TYPE& Vector3<TYPE>::y() const{
    return this->values[1];
}

template<typename TYPE>
const TYPE& Vector3<TYPE>::z() const{
    return this->values[2];
}
