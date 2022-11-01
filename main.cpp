#include <list>
#include <string>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include <utility>
#include <cmath>
#include "src/LoaderDLL.h"
#include "src/operations/Operation.h"

double add(double a, double b){
    return (a + b);
}

double abss(double x) {
    return std::abs(x);
}

//int main() {
//
////    Bebra test("add", &add, 1.5, 2.0);
////    std::cout << "result: " << test.execute() << std::endl;
//}
using unary = double*(double);
using unaryOperation = Operation<unary>*(void);

using binary = double*(double, double);
using binaryOperation = Operation<binary>;

int main() {
//    Operation test("abss", &abss);
//    std::cout << test.execute(-11.3) << std::endl;

//    Operation test("add", &add);
//    std::cout << test.execute(1, 2) << std::endl;

    HINSTANCE hi = LoadLibrary(std::string("./plugins/abss.dll").c_str());
    if (!hi) {
        throw std::exception();
    }

    auto farproc = GetProcAddress(hi, "function");
    auto foo = (unaryOperation*) farproc;
    std::cout << "a" << std::endl;
//    std::cout << foo.getPair().first << std::endl;

//    LoaderDLL<double*(double)>::f();
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

