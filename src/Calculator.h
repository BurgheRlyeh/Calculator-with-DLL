#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include <list>
#include <map>
#include <functional>
#include <windows.h>
#include "solver/Solver.h"
#include "LoaderDLL/LoaderDLL.h"

class Calculator {
    std::map<std::string, FARPROC>* functions;
    Solver* solver;

public:
    Calculator() {
        functions = getMapFunctions(LoaderDLL::getFromDLLs("./plugins/", "function"));
        solver = new Solver(functions);

//        {
//            auto find = functions->find("pi");
//            auto second = find->second;
//            auto fun = (Operation<double (*)()> *) second;
//            std::cout << (*fun)() << std::endl;
//        }
//
//        {
//            auto find = functions->find("abs");
//            auto second = find->second;
//            auto fun = (Operation<double (*)(double)> *) second;
//            std::cout << (*fun)(-5.5) << std::endl;
//        }
//
//        {
//            auto find = functions->find("pow");
//            auto second = find->second;
//            auto fun = (Operation<double (*)(double, double)> *) second;
//            std::cout << (*fun)(2, 10) << std::endl;
//        }
    }
    ~Calculator() {
        functions->clear();
    }

    double calculate(const std::string& expression) {
        return solver->parse(expression);
    }

private:
    static std::map<std::string, FARPROC>* getMapFunctions(std::list<FARPROC>* list) {
        auto mapFuncs = new std::map<std::string, FARPROC>;

        for (auto func : *list) {
            try {
                // insert pointer to map
                mapFuncs->insert(std::make_pair(
                        ((Operation<void*>*) func)->getName(),
                        func
                ));
            }
            catch (std::exception& e) {}
        }

        list->clear();
        return mapFuncs;
    }
};


#endif //CALCULATOR_CALCULATOR_H
