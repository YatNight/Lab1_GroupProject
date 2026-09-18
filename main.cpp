#include <iostream>
#include <vector>
#include "shared_types.h"

using namespace std;

int main() {
    InputData data;

    // Пряма ініціалізація вектора з явним вказівником типу Point
    data.points = vector<Point>{
        Point{1.0, 2.1},
        Point{2.0, 3.9},
        Point{3.0, 6.2},
        Point{4.0, 8.1},
        Point{5.0, 10.9}
    };

    auto input = make_shared<const InputData>(data);

    auto resultA = calculateA(input);
    if (resultA) {
        cout << "Method: " << resultA->name << " ready." << endl;
    }

    return 0;
}