#include <cmath>
#include "Operation.h"

double Sqrt(double x) {
    return sqrt(x);
}

Operation function("sqrt", &Sqrt);
