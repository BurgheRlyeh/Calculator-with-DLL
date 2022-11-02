#include <memory>
#include "Solver.h"
#include "Lexer.h"
#include "../operations/Operation.h"

double Solver::parse(const std::string &expression) {
    tokens = Lexer::lexer(expression);
    current = tokens.front();

    return expr();
}

void Solver::next() {
    if (!tokens.empty()) {
        tokens.pop_front();
    }

    current = tokens.empty() ? std::string() : tokens.front();
}

double Solver::expr() {
    double result = term();

    while (current == "+" || current == "-") {
        if (current == "+") {
            next(); // skip "+"
            result += term();
        }
        if (current == "-") {
            next(); // skip "-"
            result -= term();
        }
    }

    return result;
}

double Solver::term() {
    double result = factor();

    while (current == "*" || current == "/") {
        if (current == "*") {
            next(); // skip "*"
            result *= factor();
        }
        if (current == "/") {
            next(); // skip "/"
            result /= factor();
        }
    }

    return result;
}

double Solver::factor() {
    if (current == "(") {
        next(); // skip "("
        double result = expr();
        next(); // skip ")"
        return result;
    }
    if (current == "-") {
        next(); // skip "-"
        return -1 * factor();
    }
    if (std::isdigit(current[0])) {
        double result = std::stod(current);
        next(); // skip number
        return result;
    }

    return operation();
}

double Solver::operation() {
    auto function = functions->find(current);
    if (function == functions->end()) {
        throw std::exception();
    }

    next(); // skip function name
    next(); // skip "("

    // constant
    if (current == ")") {
        next(); // skip ")"
        return (*((Operation<double (*)()> *) function->second))();
    }

    // unary
    auto arg1 = expr();
    if (current == ")") {
        next(); // skip ")"
        return (*((Operation<double (*)(double)> *) function->second))(arg1);
    }

    // binary
    next(); // skip ","
    auto arg2 = expr();
    if (current == ")") {
        next(); // skip ")"
        return (*((Operation<double (*)(double, double)> *) function->second))(arg1, arg2);
    }
}
