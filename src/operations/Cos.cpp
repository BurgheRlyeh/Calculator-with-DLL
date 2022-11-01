#include <cmath>
#include "Operation.h"

double Cos(double x) {
    return cos(x);
}

Operation function("cos", &Cos);
