#include <cmath>
#include "Operation.h"

double Pow(double x, double y) {
    return pow(x, y);
}

Operation function("pow", &Pow);
