#include "Unary.h"

__declspec(dllexport)
Unary Cos("cos", [](double x) -> double { return cos(x); });