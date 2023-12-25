#pragma once
#include "Geometry.h"
class GEOMETRY_API Point3D
{
public:
    Point3D();
    Point3D(double inX, double inY, double inZ = 0);
    ~Point3D();

public:
    double x();
    double y();
    double z();

    void setX(double inX);
    void setY(double inY);
    void setZ(double inZ);

private:
    double mX;
    double mY;
    double mZ;
};
