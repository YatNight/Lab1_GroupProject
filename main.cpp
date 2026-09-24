#include <iostream>
#include <memory>
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

    return 0;
}