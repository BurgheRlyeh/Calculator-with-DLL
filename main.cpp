#include <windows.h>
#include <iostream>
#include "src/operations/Unary.h"
#include "src/operations/Binary.h"

int main() {
    HINSTANCE hGetProcIDDLL = LoadLibrary("./plugins/Pow.dll");

    if (!hGetProcIDDLL) {
        std::cout << "could not load the dynamic library" << std::endl;
        return EXIT_FAILURE;
    }

    // resolve function address here
    auto function = (Binary*) GetProcAddress(hGetProcIDDLL, "function");
    if (!function) {
        std::cout << "could not locate the function" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << function->getPair().first << std::endl;

    return EXIT_SUCCESS;
}

//#include <iostream>
//#include <string>
//#include "src/Calculator.h"


//int main() {
//    std::string expression;
//
//    expression = "pow(3, ((3))))))";
//    std::cout << expression << " -> "
//              << Calculator::calculate(expression) << std::endl;
//
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
//
//    return 0;
//}

