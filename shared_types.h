#pragma once
#include <vector>
#include <memory>
#include <string>

using namespace std;

struct Point {
    double x;
    double y;
};

struct InputData {
    vector<Point> points;
};

struct Result {
    string name;
    vector<double> coeffs;
    double mse;
};

unique_ptr<Result> calculateA(shared_ptr<const InputData> data);
unique_ptr<Result> calculateB(shared_ptr<const InputData> data);