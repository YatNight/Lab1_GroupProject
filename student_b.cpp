#include "shared_types.h"
#include <memory>
#include <cmath>

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
    const auto& pts = data->points;
    size_t n = pts.size();

    double sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    double sumY = 0, sumXY = 0, sumX2Y = 0;

    for (const auto& p : pts) {
        double x2 = p.x * p.x;
        sumX += p.x;
        sumX2 += x2;
        sumX3 += x2 * p.x;
        sumX4 += x2 * x2;
        sumY += p.y;
        sumXY += p.x * p.y;
        sumX2Y += x2 * p.y;
    }

    auto det = [](double a, double b, double c, 
                  double d, double e, double f, 
                  double g, double h, double i) {
        return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
    };

    double D = det(n, sumX, sumX2, sumX, sumX2, sumX3, sumX2Y, sumX3, sumX4);
    if (std::abs(D) < 1e-9) {
        return std::make_unique<Result>(Result{{0, 0, 0}, 999.0});
    }

    double D0 = det(sumY, sumX, sumX2, sumXY, sumX2, sumX3, sumX2Y, sumX3, sumX4);
    double D1 = det(n, sumY, sumX2, sumX, sumXY, sumX3, sumX2, sumX2Y, sumX4);
    double D2 = det(n, sumX, sumY, sumX, sumX2, sumXY, sumX2, sumX3, sumX2Y);

    double a0 = D0 / D;
    double a1 = D1 / D;
    double a2 = D2 / D;

    double mse = 0.0;
    for (const auto& p : pts) {
        double pred = a0 + a1 * p.x + a2 * p.x * p.x;
        mse += (pred - p.y) * (pred - p.y);
    }
    mse /= n;

    return std::make_unique<Result>(Result{{a0, a1, a2}, mse});
}