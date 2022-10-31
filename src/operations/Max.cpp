#include "Binary.h"

__declspec(dllexport)
Binary Max("max", [](double x, double y) -> double { return std::max(x, y); });
