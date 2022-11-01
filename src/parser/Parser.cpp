#include "Parser.h"
#include "Lexer.h"

double Parser::parse(const std::string &expression) {
    tokens = Lexer::lexer(expression);
    current = tokens.front();

    return expr();
}

void Parser::addUnary(Unary function) {
    unary.insert(function.getPair());
}

void Parser::addBinary(Binary function) {
    binary.insert(function.getPair());
}

void Parser::next() {
    if (!tokens.empty()) {
        tokens.pop_front();
    }

    current = tokens.empty() ? std::string() : tokens.front();
}

double Parser::expr() {
    double result = term();

    while (current == "+" || current == "-") {
        if (current == "+") {
            next();
            result += term();
        }
        if (current == "-") {
            next();
            result -= term();
        }
    }

    return result;
}

double Parser::term() {
    double result = factor();

    while (current == "*" || current == "/") {
        if (current == "*") {
            next();
            result *= factor();
        }
        if (current == "/") {
            next();
            result /= factor();
        }
    }

    return result;
}

double Parser::factor() {
    double result = 0.0;

    if (current == "(") {
        next();
        result = expr();
        next();
        return result;
    }
    if (current == "+") {
        return result;
    }
    if (current == "-") {
        next();
        result = -1 * factor();
        return result;
    }
    if (std::isdigit(current[0])) {
        result = std::stod(current);
        next();
        return result;
    }
    if (unary.contains(current)) {
        auto f = unary[current];
        next();                     // skip function name
        next();                     // skip (
        auto arg = expr();
        next();                     // skip )
        return f(arg);
    }
    if (binary.contains(current)) {
        auto f = binary[current];
        next();                     // skip function name
        next();                     // skip (
        auto arg1 = expr();
        next();                     // skip ,
        auto arg2 = expr();
        next();                     // skip )
        return f(arg1, arg2);
    }

    throw std::exception();
}
