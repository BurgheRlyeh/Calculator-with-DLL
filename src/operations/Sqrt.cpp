#include "Unary.h"

__declspec(dllexport)
Unary Sqrt("sqrt", [](double x) -> double { return sqrt(x); });