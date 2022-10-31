#include "Unary.h"

__declspec(dllexport)
Unary Log("log", [](double x) -> double { return log(x); });