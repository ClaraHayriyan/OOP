#include "Input.hpp"

#include <iostream>

std::stringstream Input::read() {
    std::string input;
    getline(std::cin, input);
    return std::stringstream{input};
}