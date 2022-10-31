#include "Lexer.h"

std::list<std::string> Lexer::lexer(const std::string &expr) {
    std::string token;
    std::list<std::string> tokens;

    for (auto c : expr) {
        // skip space
        if (std::isspace(c)) {
            continue;
        }

        // collect number and function name
        if (isdigit(c) || c == '.' || std::isalpha(c)) {
            token += c;
            continue;
        }

        // write left token
        if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }

        // skip repeated simple operations
        if (tokens.back() == std::string(1, c) && (c == '+' || c == '*' || c == '/')) {
            token.clear();
            continue;
        }

        // simple operations
        tokens.emplace_back(1, c);
    }

    // write left token
    if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
    }

    return tokens;
}
