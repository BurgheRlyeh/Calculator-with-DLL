#ifndef CALCULATOR_SOLVER_H
#define CALCULATOR_SOLVER_H

#include <cmath>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <windows.h>

class Solver {
    std::list<std::string> tokens;  // list of tokens
    std::string current;            // current token

    std::map<std::string, FARPROC>* functions;

public:
    explicit Solver(
            std::map<std::string, FARPROC>* functions = new std::map<std::string, FARPROC>()
    ) : functions(functions) {}
    ~Solver() {
        functions->clear();
    };

    double parse(const std::string& expression);    // parse expression

private:
    void next();        // update current token

    double expr();      // process summation and subtraction
    double term();      // process multiplication and division
    double factor();    // process parentheses, unary +-, numbers
    double operation(); // process dll functions
};

#endif //CALCULATOR_SOLVER_H
