#include "shared_types.h"
#include <string>

using namespace std;

unique_ptr<Result> calculateA(shared_ptr<const InputData> data) {
    auto res = make_unique<Result>();
    
    // Явно створюємо об'єкт string, щоб уникнути помилки
    res->name = string("Student A Method");
    res->mse = 0.0;
    
    return res;
}