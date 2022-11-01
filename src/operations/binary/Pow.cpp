#include "Binary.h"

__declspec(dllexport)
Binary Pow("pow", [](double x, double y) -> double { return pow(x, y); });
