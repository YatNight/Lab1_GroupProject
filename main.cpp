#include <iostream>
#include <vector>
#include "shared_types.h"

using namespace std;

int main() {
    InputData data;

    // Створюємо точки окремо
    Point p1 = {1.0, 2.1};
    Point p2 = {2.0, 3.9};
    Point p3 = {3.0, 6.2};
    Point p4 = {4.0, 8.1};
    Point p5 = {5.0, 10.9};

    // Додаємо їх у вектор перевіреним роками методом
    data.points.push_back(p1);
    data.points.push_back(p2);
    data.points.push_back(p3);
    data.points.push_back(p4);
    data.points.push_back(p5);

    // Передаємо дані далі
    auto input = make_shared<const InputData>(data);

    cout << "Initial setup ready." << endl;
    return 0;
}