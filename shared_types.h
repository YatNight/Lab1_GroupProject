#pragma once
#include <vector>
#include <memory>
// Структура для представлення експериментальної точки
struct Point {
    double x;
    double y;
};

// Спільні вхідні дані
struct InputData {
    std::vector<Point> points;
};

// Структура для результату алгоритму
struct Result {
    double a0;  // Коефіцієнт a0
    double a1;  // Коефіцієнт a1
    double mse; // Середньоквадратична похибка
};