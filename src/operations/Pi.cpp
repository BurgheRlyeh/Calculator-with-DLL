#include <cmath>
#include "Operation.h"

double Pi() {
    return M_PI;
}

Operation function("pi", &Pi);
