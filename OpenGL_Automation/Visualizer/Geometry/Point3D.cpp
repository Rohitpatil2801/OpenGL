#include "pch.h"
#include "Point3D.h"
Point3D::Point3D()
{
}

Point3D::Point3D(double x, double y, double z) :
    mX(x),
    mY(y),
    mZ(0)
{
}

Point3D::~Point3D()
{
}

double Point3D::x()
{
    return mX;
}

double Point3D::y()
{
    return mY;
}

double Point3D::z()
{
    return mZ;
}

void Point3D::setX(double inX)
{
    mX = inX;
}

void Point3D::setY(double inY)
{
    mY = inY;
}

void Point3D::setZ(double inZ)
{
    mY = inZ;
}
