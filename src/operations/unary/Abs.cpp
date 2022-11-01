#include "Unary.h"

__declspec(dllexport)
Unary Abs("abs", [](double x) -> double { return std::abs(x); });