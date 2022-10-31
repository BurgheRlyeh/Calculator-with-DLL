#include "Unary.h"

__declspec(dllexport)
Unary Sin("sin", [](double x) -> double { return sin(x); });