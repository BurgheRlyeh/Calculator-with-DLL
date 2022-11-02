#include <list>
#include <string>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include <utility>
#include <cmath>
#include <map>
#include "src/LoaderDLL.h"
#include "src/operations/Operation.h"

double add(double a, double b){
    return (a + b);
}
double Abs(double x) {
    return std::abs(x);
}

int main() {
//    Operation test("abs", &Abs);
//    std::cout << test.execute(-13) << std::endl;
//    std::cout << test(-13) << std::endl;

    HINSTANCE hi = LoadLibrary(std::string("./plugins/libAbs.dll").c_str());
    if (!hi) {
        throw std::exception();
    }

    auto farproc = GetProcAddress(hi, "function");
//    FreeLibrary(hi);

    auto foo = (Operation<double (*)(double)>*) farproc;
    std::cout << "a" << std::endl;
    std::cout << foo->getName() << std::endl;
    std::cout << (*foo)(-15) << std::endl;
    auto pair = (foo->getPair());
    std::cout << pair.first << std::endl;
    std::cout << (*pair.second)(-15) << std::endl;

//    auto list = LoaderDLL<double(*)(double)>::loadDLLs("./plugins/");
//    for (auto o : list) {
//        std::cout << o->getName() << std::endl;
//        std::cout << (*o)(5) << std::endl;
//        std::cout << std::endl;
//    }


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

