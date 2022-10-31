#ifndef BINARY_H
#define BINARY_H

#include <string>
#include <functional>
#include <utility>
#include <cmath>

class Binary {
    std::string name;
    std::function<double(double, double)> function;

public:
    Binary(std::string name, std::function<double(double, double)> function)
        : name(std::move(name)), function(std::move(function)) {}

    std::pair<std::string,  std::function<double(double, double)>> getPair() {
        return std::make_pair(name, function);
    }
};

#endif //BINARY_H
