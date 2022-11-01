#include <cmath>
#include "Operation.h"

double Tan(double x) {
    return tan(x);
}

Operation function("tan", &Tan);
