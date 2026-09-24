#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    int n = data->points.size();

    // Подвійні фігурні дужки для ініціалізації вектора всередині Result
    if (n == 0) return std::make_unique<Result>(Result{ {0.0, 0.0, 0.0}, 0.0 });

    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;

    for (const auto& pt : data->points) {
        sum_x += pt.x;
        sum_y += pt.y;
        sum_xy += pt.x * pt.y;
        sum_x2 += pt.x * pt.x;
    }

    double denominator = n * sum_x2 - sum_x * sum_x;

    double a1 = 0.0;
    double a0 = 0.0;
    if (denominator != 0.0) {
        a1 = (n * sum_xy - sum_x * sum_y) / denominator;
        a0 = (sum_y - a1 * sum_x) / n;
    }

    double sse = 0.0;
    for (const auto& pt : data->points) {
        double y_pred = a0 + a1 * pt.x;
        double error = pt.y - y_pred;
        sse += error * error;
    }
    double mse = sse / n;

    // Подвійні фігурні дужки для ініціалізації вектора всередині Result
    return std::make_unique<Result>(Result{ {a0, a1, 0.0}, a0, a1, 0.0, mse });
}