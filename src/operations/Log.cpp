#include <cmath>
#include "Operation.h"

double Log(double x) {
    return log(x);
}

Operation function("log", &Log);
