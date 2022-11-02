#include <cmath>
#include "Operation.h"

double E() {
    return std::exp(1.0);
}

Operation function("e", &E);
