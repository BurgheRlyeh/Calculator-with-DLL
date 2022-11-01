#ifndef CALCULATOR_LOADERDLL_H
#define CALCULATOR_LOADERDLL_H

#include <list>
#include <string>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include "unary/Unary.h"
#include "binary/Binary.h"

template <class T> class LoaderDLL {
public:
    static std::list<T> loadDLLs(const std::string& dir) {
        std::list<T> list;

        for (const auto& dll : std::filesystem::directory_iterator(dir)) {
            auto function = loadDLL(dll.path().string());
            if (function != nullptr) {
                list.push_back(*function);
            }
        }

        return list;
    }

private:
    static T* loadDLL(const std::basic_string<char>& path) {
        HINSTANCE hi = LoadLibrary(path.c_str());
        if (!hi) {
            throw std::exception();
        }

        return (T*) GetProcAddress(hi, "function");
    }
};

#endif //CALCULATOR_LOADERDLL_H
