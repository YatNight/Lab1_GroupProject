#include <iostream>
#include <memory>
<<<<<<< HEAD
#include "shared_types.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    auto data = std::make_shared<const InputData>(InputData{
        {{1.0, 2.1}, {2.0, 3.9}, {3.0, 9.1}, {4.0, 16.2}, {5.0, 25.0}}
    });

    auto resultB = calculateB(data);
    auto [coeffsB, mseB] = *resultB;

    std::cout << "Student B Quadratic: y = " << coeffsB[0] << " + " << coeffsB[1] << "x + " << coeffsB[2] << "x^2\n";
    std::cout << "MSE: " << mseB << "\n";
=======
#include <windows.h>
#include "shared_types.h"

// Оголошення функцій обох студентів
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    // Встановлюємо кодування UTF-8 для правильного відображення кирилиці
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Спільні вхідні дані для обох алгоритмів через shared_ptr
    auto data = std::make_shared<const InputData>(InputData{
        {
            {1.0, 2.1},
            {2.0, 3.8},
            {3.0, 6.2},
            {4.0, 8.0},
            {5.0, 10.3}
        }
        });

    // 1. Виклик алгоритму Студента А (Лінійна апроксимація)
    auto resultA = calculateA(data);
    auto [a0_a, a1_a, a2_a, mse_a] = *resultA; // Structured bindings

    std::cout << "--- Метод Студента А (Лінійна апроксимація) ---\n";
    std::cout << "Отримана модель: y = " << a0_a << " + " << a1_a << " * x\n";
    std::cout << "Середньоквадратична похибка (MSE): " << mse_a << "\n\n";

    // 2. Виклик алгоритму Студента Б (Квадратична апроксимація)
    auto resultB = calculateB(data);
    auto [a0_b, a1_b, a2_b, mse_b] = *resultB; // Structured bindings

    std::cout << "--- Метод Студента Б (Квадратична апроксимація) ---\n";
    std::cout << "Отримана модель: y = " << a0_b << " + " << a1_b << " * x + " << a2_b << " * x^2\n";
    std::cout << "Середньоквадратична похибка (MSE): " << mse_b << "\n";
>>>>>>> ad19054 (Resolve merge conflict and finalize Lab 1)

    return 0;
}