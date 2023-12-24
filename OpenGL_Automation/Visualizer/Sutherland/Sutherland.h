#pragma once
#include "pch.h"
#include <tuple>
#include "Line.h"
#include <vector>

class SUTHERLAND_API Sutherland {
public:
    static Line clip(Line l, std::vector<Line>sides);

private:
    static int getCode(double x, double y, double xMin, double yMin, double xMax, double yMax);
};




