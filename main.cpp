#include <iostream>
#include <memory>
#include <windows.h>
#include "shared_types.h"

// Оголошення функцій обох студентів
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    // Встановлення кодування UTF-8 для правильного відображення кирилиці
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Ініціалізація даних з правильними дужками
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
    std::cout << "--- Метод Студента А (Лінійна апроксимація) ---\n";
    std::cout << "Отримана модель: y = " << resultA->a0 << " + " << resultA->a1 << " * x\n";
    std::cout << "Середньоквадратична похибка (MSE): " << resultA->mse << "\n\n";

    // 2. Виклик алгоритму Студента Б (Квадратична апроксимація)
    auto resultB = calculateB(data);
    std::cout << "--- Метод Студента Б (Квадратична апроксимація) ---\n";
    std::cout << "Отримана модель: y = " << resultB->a0 << " + " << resultB->a1 << " * x + " << resultB->a2 << " * x^2\n";
    std::cout << "Середньоквадратична похибка (MSE): " << resultB->mse << "\n";

    return 0;
}