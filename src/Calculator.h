#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include <list>
#include <map>
#include <functional>
#include "parser/Parser.h"

class Calculator {
public:
    static double calculate(const std::string& expression) {
        return (new Parser())->parse(expression);
    }
};


#endif //CALCULATOR_CALCULATOR_H
