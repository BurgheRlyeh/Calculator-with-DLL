#include "Binary.h"

__declspec(dllexport)
Binary Min("min", [](double x, double y) -> double { return std::min(x, y); });
