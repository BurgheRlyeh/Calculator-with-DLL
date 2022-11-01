#include <cmath>
#include "Operation.h"

double Sin(double x) {
    return sin(x);
}

Operation function("sin", &Sin);
