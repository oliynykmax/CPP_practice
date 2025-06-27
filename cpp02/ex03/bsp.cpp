#include "Point.hpp"
#include "Fixed.hpp"
#include <vector>
#include <iostream>
#include <cmath>


static Fixed sign (Point p1, Point p2, Point p3)
{
    float result = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
    (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
    return Fixed(result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed zero(0);
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);
    if (d1 == zero || d2 == zero || d3 == zero)
         return false;
    bool has_neg = (d1 < zero) || (d2 < zero) || (d3 < zero);
    bool has_pos = (d1 > zero) || (d2 > zero) || (d3 > zero);
    return !(has_neg && has_pos);
}
