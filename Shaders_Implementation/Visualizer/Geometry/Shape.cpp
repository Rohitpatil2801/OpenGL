#include "pch.h"
#include "Shape.h"

Shape::Shape(Point3D min, Point3D max)
{
	Point3D p1 = min;
	Point3D p2 = Point3D(max.x(), min.y());
	Point3D p3 = max;
	Point3D p4 = Point3D(min.x(), max.y());

	Line l1 = Line(p1, p2);
	Line l2 = Line(p2, p3);
	Line l3 = Line(p3, p4);
	Line l4 = Line(p4, p1);

	mLines.push_back(l1);
	mLines.push_back(l2);
	mLines.push_back(l3);
	mLines.push_back(l4);
}

Shape::~Shape()
{

}

std::vector<Line> Shape::getShape()
{
	return mLines;
}