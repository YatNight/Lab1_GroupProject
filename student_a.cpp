#include "shared_types.h"
#include <memory>

// Функція Студента А
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    // Перевірка на порожні дані
    if (!data || data->points.empty()) {
        return std::make_unique<Result>(Result{ 0.0, 0.0, 0.0 });
    }

    size_t n = data->points.size();
    double sum_x = 0.0, sum_y = 0.0, sum_xx = 0.0, sum_xy = 0.0;

    // Обчислення сум для системи нормальних рівнянь
    for (const auto& pt : data->points) {
        sum_x += pt.x;
        sum_y += pt.y;
        sum_xx += pt.x * pt.x;
        sum_xy += pt.x * pt.y;
    }

    double denominator = n * sum_xx - sum_x * sum_x;
    double a1 = 0.0;
    double a0 = 0.0;

    // Обчислення коефіцієнтів a0 та a1
    if (denominator != 0.0) { // Захист від ділення на нуль
        a1 = (n * sum_xy - sum_x * sum_y) / denominator;
        a0 = (sum_y - a1 * sum_x) / n;
    }

    // Обчислення середньоквадратичної похибки (MSE)
    double sse = 0.0; // Сума квадратів помилок
    for (const auto& pt : data->points) {
        double y_pred = a0 + a1 * pt.x;
        double error = pt.y - y_pred;
        sse += error * error;
    }
    double mse = sse / n;

    // Повертаємо результат через unique_ptr
    return std::make_unique<Result>(Result{ a0, a1, mse });
}