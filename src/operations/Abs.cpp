#include "Operation.h"

double Abs(double x) {
    return std::abs(x);
}

Operation function("abs",  &Abs);
