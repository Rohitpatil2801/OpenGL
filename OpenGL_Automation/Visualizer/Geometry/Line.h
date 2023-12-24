#pragma once
#include "Point3D.h"
class GEOMETRY_API Line
{
public:
    Line();
    Line(Point3D start, Point3D end);
    ~Line();


    Point3D& getStart();
    Point3D& getEnd();

private:
    Point3D mStart;
    Point3D mEnd;
};


