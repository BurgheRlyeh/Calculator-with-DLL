#ifndef LOG_OPERATION_H
#define LOG_OPERATION_H

#include <string>
#include <functional>
#include <utility>

template <typename Function>
class Operation {
    std::string name;
    Function function;

public:
    Operation(std::string name, Function function) : name(std::move(name)), function(function) {}

    std::string getName() {
        return name;
    }

    template <typename... Args>
    double operator()(Args&&... args) {
        return std::bind(function, std::forward<Args>(args)...)();
    }
};

#endif //LOG_OPERATION_H
