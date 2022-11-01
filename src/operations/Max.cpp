#include "Operation.h"

double Max(double x, double y) {
    return std::max(x, y);
}

Operation function("max", &Max);
