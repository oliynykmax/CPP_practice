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
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
         return false;
    bool has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));
    return !(has_neg && has_pos);
}
