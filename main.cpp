#include <iostream>
#include <memory>
#include <windows.h> // Додаємо бібліотеку для роботи з кодуванням консолі Windows
#include "shared_types.h"

// Оголошення функції Студента А
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);

int main() {
    // Встановлюємо кодування UTF-8 для правильного відображення кирилиці
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // 1. Створення спільного об'єкта вхідних даних через shared_ptr
    auto data = std::make_shared<const InputData>(InputData{
        // ... (весь ваш попередній код залишається без змін)
        {
            {1.0, 2.1},
            {2.0, 3.8},
            {3.0, 6.2},
            {4.0, 8.0},
            {5.0, 10.3}
        }
        });

    // 2. Виклик алгоритму Студента А
    auto resultA = calculateA(data);

    // 3. Отримання полів результату за допомогою structured bindings (C++17/20)
    auto [a0, a1, mse] = *resultA;

    // 4. Виведення результатів
    std::cout << "--- Метод Студента А (Лінійна апроксимація) ---\n";
    std::cout << "Отримана модель: y = " << a0 << " + " << a1 << " * x\n";
    std::cout << "Середньоквадратична похибка (MSE): " << mse << "\n";

    return 0;
}