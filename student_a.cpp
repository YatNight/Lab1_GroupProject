#include "shared_types.h"
#include <memory>

<<<<<<< HEAD
// Функція Студента А
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    // Перевірка на порожні дані
    if (!data || data->points.empty()) {
        return std::make_unique<Result>(Result{ 0.0, 0.0, 0.0 });
=======
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    if (!data || data->points.empty()) {
        return std::make_unique<Result>(Result{ 0.0, 0.0, 0.0, 0.0 });
>>>>>>> ad19054 (Resolve merge conflict and finalize Lab 1)
    }

    size_t n = data->points.size();
    double sum_x = 0.0, sum_y = 0.0, sum_xx = 0.0, sum_xy = 0.0;

<<<<<<< HEAD
    // Обчислення сум для системи нормальних рівнянь
=======
>>>>>>> ad19054 (Resolve merge conflict and finalize Lab 1)
    for (const auto& pt : data->points) {
        sum_x += pt.x;
        sum_y += pt.y;
        sum_xx += pt.x * pt.x;
        sum_xy += pt.x * pt.y;
    }

    double denominator = n * sum_xx - sum_x * sum_x;
    double a1 = 0.0;
    double a0 = 0.0;

<<<<<<< HEAD
    // Обчислення коефіцієнтів a0 та a1
    if (denominator != 0.0) { // Захист від ділення на нуль
=======
    if (denominator != 0.0) {
>>>>>>> ad19054 (Resolve merge conflict and finalize Lab 1)
        a1 = (n * sum_xy - sum_x * sum_y) / denominator;
        a0 = (sum_y - a1 * sum_x) / n;
    }

<<<<<<< HEAD
    // Обчислення середньоквадратичної похибки (MSE)
    double sse = 0.0; // Сума квадратів помилок
=======
    double sse = 0.0;
>>>>>>> ad19054 (Resolve merge conflict and finalize Lab 1)
    for (const auto& pt : data->points) {
        double y_pred = a0 + a1 * pt.x;
        double error = pt.y - y_pred;
        sse += error * error;
    }
    double mse = sse / n;

<<<<<<< HEAD
    // Повертаємо результат через unique_ptr
    return std::make_unique<Result>(Result{ a0, a1, mse });
=======
    return std::make_unique<Result>(Result{ a0, a1, 0.0, mse });
>>>>>>> ad19054 (Resolve merge conflict and finalize Lab 1)
}