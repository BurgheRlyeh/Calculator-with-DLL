#include <iostream>
#include "Lexer.h"

std::list<std::string> Lexer::lexer(const std::string &expr) {
    std::string token;
    std::list<std::string> tokens;

    int bracketNum{};

    for (auto c : expr) {
        // skip space
        if (std::isspace(c)) {
            continue;
        }

        // collect number
        if (isdigit(c) || c == '.') {
            token += c;
            continue;
        }

        // collect function name
        if (std::isalpha(c)) {
            token += c;
            continue;
        }

        // write left token
        if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }

        // simple operations
        if (c == '(') {
            ++bracketNum;
        }
        else if (c == ')') {
            --bracketNum;
            if (bracketNum < 0) {
                throw std::exception();
            }
        }
        tokens.emplace_back(1, c);
    }

    // write left token
    if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
    }

    return tokens;
}
