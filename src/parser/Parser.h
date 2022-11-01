#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H

#include <cmath>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <utility>
#include "../operations/unary/Unary.h"
#include "../operations/binary/Binary.h"

class Parser {
    std::list<std::string> tokens;  // list of tokens
    std::string current;            // current token

    std::map<std::string, std::function<double(double)>> unary;             // map of unary functions
    std::map<std::string, std::function<double(double, double)>> binary;    // map of binary functions

public:
    Parser() = default;
    ~Parser() = default;

    double parse(const std::string& expression);

    void addUnary(Unary function);
    void addBinary(Binary function);

private:
    void next();        // update current token

    double expr();      // process summation and subtraction
    double term();      // process multiplication and division
    double factor();    // process parentheses, unary minus, numbers and functions
};

#endif //CALCULATOR_PARSER_H
