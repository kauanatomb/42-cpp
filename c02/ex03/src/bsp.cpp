#include "bsp.hpp"

#include "Point.hpp"

// Triangulo cross product (a, b, c)
float cross(Point const &a, Point const &b, Point const &c) {
    float abx = b.getX().toFloat() - a.getX().toFloat();
    float aby = b.getY().toFloat() - a.getY().toFloat();
    float acx = c.getX().toFloat() - a.getX().toFloat();
    float acy = c.getY().toFloat() - a.getY().toFloat();
    return abx * acy - aby * acx;
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    float c1 = cross(a, b, p);
    float c2 = cross(b, c, p);
    float c3 = cross(c, a, p);

    // if any cross result is 0 the point is on the edge so is false
    if (c1 == 0 || c2 == 0 || c3 == 0)
        return false;

    // They need to be all positives or all negatives
    bool hasNeg = (c1 < 0) || (c2 < 0) || (c3 < 0);
    bool hasPos = (c1 > 0) || (c2 > 0) || (c3 > 0);

    return !(hasNeg && hasPos);
}

