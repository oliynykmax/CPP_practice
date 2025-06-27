#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <vector>

bool bsp(Point const a, Point const b, Point const c, Point const point);
int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    std::vector<Point> test_points = {
        Point(4, 4), Point(0, 0), Point(10, 0), Point(5, 10),
        Point(5, 5), Point(2.5, 5), Point(1.2f, 3.0f),
        Point(5, 11), Point(6, 2), Point(-1, -1), Point(5, -1)
    };

    for (auto& p : test_points) {
        std::cout << "Testing point (" << p.getX() << ", " << p.getY() << "): ";
        if (bsp(a, b, c, p))
            std::cout << "Inside\n";
        else
            std::cout << "Outside\n";
    }
}
