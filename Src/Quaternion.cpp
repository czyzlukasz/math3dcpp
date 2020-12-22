#include <Quaternion.hpp>
#include <cmath>
#include <Vector.hpp>

template struct Quaternion<double>;
template struct Quaternion<float>;


template<typename TYPE>
Quaternion<TYPE>::Quaternion(const Vector3<TYPE>& eulerAngles) {
    // Convert degrees to radians
    constexpr auto d2r = [](TYPE degrees) -> TYPE{
        return degrees / 180. * M_PI;
    };

    const TYPE cr = std::cos(d2r(eulerAngles.x()) / 2.);
    const TYPE sr = std::sin(d2r(eulerAngles.x()) / 2.);
    const TYPE cp = std::cos(d2r(eulerAngles.y()) / 2.);
    const TYPE sp = std::sin(d2r(eulerAngles.y()) / 2.);
    const TYPE cy = std::cos(d2r(eulerAngles.z()) / 2.);
    const TYPE sy = std::sin(d2r(eulerAngles.z()) / 2.);

    w = cr * cp * cy + sr * sp * sy;
    x = sr * cp * cy - cr * sp * sy;
    y = cr * sp * cy + sr * cp * sy;
    z = cr * cp * sy - sr * sp * cy;
}

template<typename TYPE>
Vector3<TYPE> Quaternion<TYPE>::toEulerAngles() const {
    Vector3<TYPE> result;
    result.x() = std::atan2(2. * (w * x + y * z), 1. - 2. * (x * x + y * y));
    result.y() = std::asin(2. * (w * y - z * x));
    result.z() = std::atan2(2. * (w * z + x * y), 1. - 2. * (y * y + z * z));
    // Convert radians to degrees
    constexpr auto r2d = [](TYPE degrees) -> TYPE{
        return degrees / M_PI * 180.;
    };
    result.x() = r2d(result.x());
    result.y() = r2d(result.y());
    result.z() = r2d(result.z());

    return result;
}
