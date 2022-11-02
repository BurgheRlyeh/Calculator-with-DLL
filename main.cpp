#include <list>
#include <cassert>
#include "src/Calculator.h"

int main() {
    auto* calc = new Calculator();

    assert(calc->calculate("(4+5+9)*2-(10/2)+55-6") == 80);
    assert(calc->calculate("pow(cos(1),2)+pow(sin(1),2)") == 1);
    assert(calc->calculate("log(pow(e(),sqrt(4)))") == 2);
    assert(calc->calculate("2*log(pow(e(),4)) + log(pow(e(),5)) -log(pow(e(),3))") == 10);
    assert(calc->calculate("2*sin(pi())*cos(pi()) - sin(2 * pi())") == 0);

    bool exceptionThrown;

    exceptionThrown = false;
    try { calc->calculate("1 / ()"); }
    catch(...) { exceptionThrown = true; }
    assert(exceptionThrown);

    exceptionThrown = false;
    try { calc->calculate("sin(1))"); }
    catch(...) { exceptionThrown = true; }
    assert(exceptionThrown);

    exceptionThrown = false;
    try { calc->calculate("unknown(60)"); }
    catch(...) { exceptionThrown = true; }
    assert(exceptionThrown);

    exceptionThrown = false;
    try { calc->calculate("фжлдфва"); }
    catch(...) { exceptionThrown = true; }
    assert(exceptionThrown);

}
