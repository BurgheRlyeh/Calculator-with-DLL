#ifndef CALCULATOR_LOADERDLL_H
#define CALCULATOR_LOADERDLL_H

#include <list>
#include <string>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include <map>
#include "../operations/Operation.h"

class LoaderDLL {
public:
    static std::list<FARPROC>* getFromDLLs(const std::string& dir, const std::string& entityName);
};

#endif //CALCULATOR_LOADERDLL_H
