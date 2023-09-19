#include "Printer.hpp"

#include <iostream>

void Printer::output(Result result) {
    std::cout << result << std::endl;
}

void Printer::output(std::string message) {
    std::cout << message << std::endl;
}