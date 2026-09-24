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

    double a0;
    double a1;
    double a2;  // Обов'язково має бути це поле!

    double mse;
};