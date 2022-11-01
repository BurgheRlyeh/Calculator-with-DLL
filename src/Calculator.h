#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include <list>
#include <map>
#include <functional>
#include "parser/Parser.h"

class Calculator {


public:
    Calculator() {

    }

    static double calculate(const std::string& expression) {
        return (new Parser())->parse(expression);
    }

private:

};


#endif //CALCULATOR_CALCULATOR_H
