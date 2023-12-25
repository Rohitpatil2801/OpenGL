// Sutherland.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "framework.h"
#include "Sutherland.h"

Line Sutherland::clip(Line l, std::vector<Line> sides) {

    double x1 = l.getStart().x();
    double y1 = l.getStart().y();
    double x2 = l.getEnd().x();
    double y2 = l.getEnd().y();

    double xMin = sides.at(0).getStart().x();
    double yMin = sides.at(0).getStart().y();
    double xMax = sides.at(2).getStart().x();
    double yMax = sides.at(2).getStart().y();


    int code1 = getCode(x1, y1, xMin, yMin, xMax, yMax);
    int code2 = getCode(x2, y2, xMin, yMin, xMax, yMax);

    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        }
        else if ((code1 & code2) != 0) {
            break;
        }
        else {
            int code_out;
            double x = 0, y = 0;

            if (code1 != 0) {
                code_out = code1;
            }
            else {
                code_out = code2;
            }

            if (code_out & 8) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (code_out & 4) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (code_out & 2) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else if (code_out & 1) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = getCode(x1, y1, xMin, yMin, xMax, yMax);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = getCode(x2, y2, xMin, yMin, xMax, yMax);
            }
        }
    }
    return Line(Point3D(x1, y1), Point3D(x2, y2));
}

int Sutherland::getCode(double x, double y, double xMin, double yMin, double xMax, double yMax) {
    double inside = 0, lft = 1, rht = 2, bottom = 4, top = 8;
    double code = inside;

    if (x < xMin) {
        code = lft;
    }
    else if (x > xMax) {
        code = rht;
    }

    if (y < yMin) {
        code = bottom;
    }
    else if (y > yMax) {
        code = top;
    }

    return code;
}
