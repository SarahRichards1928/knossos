#ifndef POINT_H
#define POINT_H

#include "shape.h"

class color4F;
class Point : public Shape
{
public:
    Point(Transform *transform = 0, Coordinate *origin = 0, uint size = 0, color4F *color = 0);
    uint size;
    color4F *color;
};

#endif // POINT_H
