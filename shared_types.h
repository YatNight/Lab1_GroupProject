#pragma once
#include <vector>

struct Point {
    double x;
    double y;
};

struct InputData {
    std::vector<Point> points;
};

struct Result {
    std::vector<double> coefficients;
    double mse;
};