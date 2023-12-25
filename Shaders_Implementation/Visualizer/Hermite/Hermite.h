#pragma once
#include "pch.h"
#include <vector>
#include "Point3D.h"
using namespace std;

class HERMITE_API Hermite
{
public:
	Hermite(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3);
	~Hermite();

	void drawCurve(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3, vector<float>& mVertices, vector<float>& mColors);

private:
	Point3D mP0;
	Point3D mP1;
	Point3D mP2;
	Point3D mP3;

	float blend1;
	float blend2;
	float blend3;
	float blend4;

};