#include <Coordinates.hpp>
#include <cmath>

Coordinates::Coordinates() : latitude(0), longitude(0){

}

Coordinates::Coordinates(const Coordinates::Latitude& latitude, const Coordinates::Longitude& longitude)
    : latitude(latitude), longitude(longitude){

}

std::tuple<unsigned int, unsigned int, float, bool> Coordinates::ddToDms(const double& dd) {
    const bool isPositive = dd >= 0.;
    const double absoluteValue = std::abs(dd);
    const unsigned int degrees = std::floor(absoluteValue);
    const double minutesInDouble = (absoluteValue - degrees) * 60.;
    const unsigned int minutes = std::floor(minutesInDouble);
    const float seconds = static_cast<float>(minutesInDouble - minutes) * 60.f;

    return {degrees, minutes, seconds, isPositive};
}

std::tuple<unsigned int, unsigned int, float, char> Coordinates::getHumanReadableLatitude() const {
    const auto [d, m, s, isPositive] = ddToDms(latitude);
    return {d, m, s, isPositive ? 'N' : 'S'};
}

std::tuple<unsigned int, unsigned int, float, char> Coordinates::getHumanReadableLongitude() const {
    const auto [d, m, s, isPositive] = ddToDms(longitude);
    return {d, m, s, isPositive ? 'E' : 'W'};
}
