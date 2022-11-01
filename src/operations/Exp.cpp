#include <cmath>
#include "Operation.h"

double Exp(double x) {
    return exp(x);
}

Operation function("exp", &Exp);
