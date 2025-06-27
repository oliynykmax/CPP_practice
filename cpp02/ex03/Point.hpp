#ifndef POINT_HPP
#define POINT_HPP

class Point {
public:
    Point();
    Point(const float x, const float y);
    ~Point();
    Point(const Point& other);
    Point& operator=(const Point& other);
    float getX() const;
    float getY() const;
private:
    float _x;
    float _y;
};

#endif
