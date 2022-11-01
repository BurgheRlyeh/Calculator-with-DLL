#ifndef LOG_OPERATION_H
#define LOG_OPERATION_H

#include <string>
#include <functional>

template <typename Function>
class Operation {
    std::string name;
    Function function;

public:
    Operation(std::string  name, Function function) : name(std::move(name)), function(function) {}

    template <typename... Args>
    double execute(Args&&... args) {
        return std::bind(function, std::forward<Args>(args)...)();
    }

    std::pair<std::string, Function> getPair() {
        return std::make_pair(name, function);
    }
};

#endif //LOG_OPERATION_H
