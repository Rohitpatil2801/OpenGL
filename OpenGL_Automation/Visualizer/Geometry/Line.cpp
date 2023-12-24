#include "pch.h"
#include "Line.h"
Line::Line()
{

}

Line::Line(Point3D start, Point3D end) :
    mStart(start),
    mEnd(end)
{

}

Line::~Line()
{

}

Point3D& Line::getStart()
{
    return mStart;
}

Point3D& Line::getEnd()
{
    return mEnd;
}

