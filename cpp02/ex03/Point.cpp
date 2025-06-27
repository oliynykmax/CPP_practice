#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::~Point() {}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        _x = other.getX();
        _y = other.getY();
    }
    return *this;
}

float Point::getX() const {
    return _x;
}

float Point::getY() const {
    return _y;
}
