#ifndef CALCULATOR_LOADERDLL_H
#define CALCULATOR_LOADERDLL_H

#include <list>
#include <string>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include "operations/Operation.h"



template <class T> class LoaderDLL {
public:
    static void f() {
//        auto list = LoaderDLL<double(*)(double)>::loadDLLs("./plugins/");
//
//        for (auto o : list) {
//            std::cout << o->getPair().first << std::endl;
//            std::cout << o->getPair().second(5) << std::endl;
//            std::cout << std::endl;
//        }
    }

    static std::list<Operation<T>*> loadDLLs(const std::string& dir) {
        std::list<Operation<T>*> list;

        for (const auto& dll : std::filesystem::directory_iterator(dir)) {
            try {
                auto function = loadDLL(dll.path().string());
                std::cout << "a" << std::endl;
                if (function != nullptr) {
                    list.insert(function);
                }
            }
            catch (std::exception e) {}
        }

        return list;
    }

private:
    static Operation<T>* loadDLL(const std::basic_string<char>& path) {
        HINSTANCE hi = LoadLibrary(path.c_str());
        if (!hi) {
            throw std::exception();
        }

        return (Operation<T>*) GetProcAddress(hi, "function");
    }
};

#endif //CALCULATOR_LOADERDLL_H
