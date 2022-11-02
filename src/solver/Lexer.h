#ifndef CALCULATOR_LEXER_H
#define CALCULATOR_LEXER_H

#include <list>
#include <string>

class Lexer {
public:
    static std::list<std::string> lexer(const std::string &expr);
};

#endif //CALCULATOR_LEXER_H
