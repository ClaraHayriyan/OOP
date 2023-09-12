#include "Command.hpp"

#include <cstdlib> // std::exit
#include <ios> // std::boolalpha

// Arithmetic operations

std::string Add::execute(std::stringstream args) {
    double result {0};
    double num;
    while(args >> num)
        result += num;
    std::stringstream stream;
    stream << result;
    return stream.str();
}

std::string Sub::execute(std::stringstream args) {
    double arg1;
    double arg2;
    args >> arg1;
    args >> arg2;
    std::stringstream stream;
    stream << arg1 - arg2;
    return stream.str();
}

std::string Mul::execute(std::stringstream args) {
    double result {1};
    double num;
    while(args >> num)
        result *= num;
    std::stringstream stream;
    stream << result;
    return stream.str();
}

std::string Div::execute(std::stringstream args) {
    double arg1;
    double arg2;
    args >> arg1;
    args >> arg2;
    std::stringstream stream;
    stream << arg1 / arg2;
    return stream.str();
}

// Logical operations

std::string And::execute(std::stringstream args) {
    bool result {1};
    bool arg;
    while(args >> std::boolalpha >> arg)
        result = result && arg;
    std::stringstream stream;
    stream << std::boolalpha << result;
    return stream.str();
}

std::string Or::execute(std::stringstream args) {
    bool result {false};
    bool arg;
    while(args >> std::boolalpha >> arg)
        result = result || arg;
    std::stringstream stream;
    stream << std::boolalpha << result;
    return stream.str();
}

std::string Xor::execute(std::stringstream args) {
    bool result {false};
    bool arg;
    while(args >> std::boolalpha >> arg)
        result = (!result && arg) || (!arg && result);
    std::stringstream stream;
    stream << std::boolalpha << result;
    return stream.str();
}

std::string Not::execute(std::stringstream args) {
    bool result;
    args >> std::boolalpha >> result;
    result = !result;
    std::stringstream stream;
    stream << std::boolalpha << result;
    return stream.str();
}

std::string Quit::execute(std::stringstream args) {
    std::exit(0);
}