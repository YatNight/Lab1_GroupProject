#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    auto data = std::make_shared<const InputData>(InputData{
        {{1.0, 2.1}, {2.0, 3.9}, {3.0, 9.1}, {4.0, 16.2}, {5.0, 25.0}}
    });

    // Результат Студента А
    auto resultA = calculateA(data);
    auto [coeffsA, mseA] = *resultA;

    // Результат Студента Б
    auto resultB = calculateB(data);
    auto [coeffsB, mseB] = *resultB;

    std::cout << "--- Student A (Linear) ---\n";
    std::cout << "y = " << coeffsA[0] << " + " << coeffsA[1] << "*x, MSE = " << mseA << "\n\n";

    std::cout << "--- Student B (Quadratic) ---\n";
    std::cout << "y = " << coeffsB[0] << " + " << coeffsB[1] << "*x + " << coeffsB[2] << "*x^2, MSE = " << mseB << "\n";

    return 0;
}