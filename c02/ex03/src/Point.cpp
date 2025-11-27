#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float nb1, const float nb2) : x(nb1), y(nb2) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }