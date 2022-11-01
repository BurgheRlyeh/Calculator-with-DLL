#include "Unary.h"

__declspec(dllexport)
Unary Exp("exp", [](double x) -> double { return exp(x); });