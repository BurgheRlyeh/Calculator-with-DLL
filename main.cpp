#include <list>
#include <string>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include "src/operations/unary/Unary.h"
#include "src/operations/binary/Binary.h"
#include "src/operations/LoaderDLL.h"

int main() {
    auto list = LoaderDLL<Unary>::loadDLLs("./plugins/unary/");
    for (auto bebra : list) {
        std::cout << bebra.getPair().first << std::endl;
    }
}

//#include <iostream>
//#include <string>
//#include "src/Calculator.h"


//int main() {
//    std::string expression;
//
//    expression = "+";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;

//    expression = "-14.7/3*-2 + 0.2 - sqr(3) - 1 + sqr(sqr(2)) - 16";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;
//
//    expression = "3+2*2";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;
//
//    expression = "3/2";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;
//
//    expression = "3+5 / 2";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;
//
//    expression = "(1 + 22) * 3";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;
//
//    expression = "1 + 1";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;
//
//    expression = "100000000/1/2/3/4/5/6/7/8/9/10";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;

//    return 0;
//}

