// BSpline.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "BSpline.h"
#include <vector>

using namespace std;

BSpline::BSpline(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3) :
    degree(3),
    mP0(inP0),
    mP1(inP1),
    mP2(inP2),
    mP3(inP3)
{
    // Generate a simple knot vector for an open B-spline
    int n = 4;
    int m = n + degree + 1;

    for (int i = 0; i <= m; ++i) {
        if (i < degree + 1) {
            knots.push_back(0.0);
        }
        else if (i <= n) {
            knots.push_back(static_cast<double>(i - degree));
        }
        else {
            knots.push_back(static_cast<double>(n - degree + 1));
        }
    }
}

BSpline::~BSpline()
{

}

double BSpline::basisFunction(int i, int k, double t) {
    if (k == 0) {
        return (t >= knots[i] && t < knots[i + 1]) ? 1.0 : 0.0;
    }

    double denom1 = knots[i + k] - knots[i];
    double term1 = (denom1 != 0.0) ? ((t - knots[i]) / denom1) * basisFunction(i, k - 1, t) : 0.0;

    double denom2 = knots[i + k + 1] - knots[i + 1];
    double term2 = (denom2 != 0.0) ? ((knots[i + k + 1] - t) / denom2) * basisFunction(i + 1, k - 1, t) : 0.0;

    return term1 + term2;
}

void BSpline::evaluate(double t, vector<float>& mVertices, vector<float>& mColors)
{
    int n = 4;
    double x = 0.0, y = 0.0, z = 0.0;

    for (int i = 0; i < n; ++i) {
        double basis = basisFunction(i, degree, t);
        x += basis * knots[i];
        y += basis * knots[i + 1];
        z += basis * knots[i + 2];
    }

    mVertices.push_back(x);
    mVertices.push_back(y);
    mVertices.push_back(z);

    mColors.push_back(0.0f);
    mColors.push_back(1.0f);
    mColors.push_back(0.0f);
}

void BSpline::drawCurveBspline(vector<float>& mVertices, vector<float>& mColors)
{
    for (double t = 0.0; t <= 1.0; t += 0.01)
    {
        evaluate(t, mVertices, mColors);
    }
}
