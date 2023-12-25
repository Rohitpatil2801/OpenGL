#pragma once
#include "pch.h"
#include "Point3D.h"
#include <iostream>
#include <vector>

using namespace std;

class BSPLINE_API BSpline{
public:
    BSpline(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3);
    ~BSpline();

    double basisFunction(int i, int k, double t);
    void evaluate(double t, vector<float>& mVertices, vector<float>& mColors);
    void drawCurveBspline(vector<float>& mVertices, vector<float>& mColors);

private:
    std::vector<double> knots;

    int degree;

    Point3D mP0;
    Point3D mP1;
    Point3D mP2;
    Point3D mP3;
};
