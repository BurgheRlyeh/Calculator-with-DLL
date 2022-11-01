#include "Operation.h"

double Min(double x, double y) {
    return std::min(x, y);
}

Operation function("min", &Min);
