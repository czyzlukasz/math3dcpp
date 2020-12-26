#ifndef MATH3DCPP_COORDINATES_HPP
#define MATH3DCPP_COORDINATES_HPP


#include <tuple>

struct Coordinates {
    struct Latitude{
        constexpr explicit Latitude(double value) : value(value){}
        constexpr operator double () const{
            return value;
        }
        double value;
    };
    struct Longitude{
        constexpr explicit Longitude(double value) : value(value){}
        constexpr operator double () const{
            return value;
        }
        double value;
    };

    Coordinates();
    Coordinates(const Latitude& latitude, const Longitude& longitude);

private:
    static std::tuple<unsigned int, unsigned int, float, bool> ddToDms(const double& dd);

public:
    std::tuple<unsigned int, unsigned int, float, char> getHumanReadableLatitude() const;
    std::tuple<unsigned int, unsigned int, float, char> getHumanReadableLongitude() const;

    Latitude latitude;
    Longitude longitude;
};

constexpr Coordinates::Latitude operator "" _N (long double val){
    return Coordinates::Latitude(static_cast<double>(val));
}

constexpr Coordinates::Latitude operator "" _S (long double val){
    return Coordinates::Latitude(static_cast<double>(-val));
}

constexpr Coordinates::Longitude operator "" _E (long double val){
    return Coordinates::Longitude(static_cast<double>(val));
}

constexpr Coordinates::Longitude operator "" _W (long double val){
    return Coordinates::Longitude(static_cast<double>(-val));
}

#endif //MATH3DCPP_COORDINATES_HPP
