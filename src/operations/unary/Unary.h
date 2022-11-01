#ifndef UNARY_H
#define UNARY_H

#include <string>
#include <functional>
#include <utility>
#include <cmath>

class Unary {
    std::string name;
    std::function<double(double)> function;

public:
    Unary(std::string name, std::function<double(double)> function)
        : name(std::move(name)), function(std::move(function)) {}

    std::pair<std::string,  std::function<double(double)>> getPair() {
        return std::make_pair(name, function);
    }
};


#endif //UNARY_H
