#include "Commands.hpp"

#include <cstdlib> // std::exit

/// Arithmetic operations

// Add

void Add::validate() {

}

Result Add::execute() {
    Result result {0};
    for(auto op : operands)
        result += std::get<1>(op);
    return result;
}

OptionSet Add::options { "op", "ops" };

// Sub

void Sub::validate() {
    
}

Result Sub::execute() {
    return std::get<1>(operands[0]) - std::get<1>(operands[1]);
}

OptionSet Sub::options { "op", "ops" };

// Mul

void Mul::validate() {
    
}

Result Mul::execute() {
    Result result {1};
    for(auto op : operands)
        result *= std::get<1>(op);
    return result;
}

OptionSet Mul::options { "op", "ops" };

// Div

void Div::validate() {
    
}

Result Div::execute() {
    return std::get<1>(operands[0]) / std::get<1>(operands[1]);
}

OptionSet Div::options { "op", "ops" };

/// Logical operations

// And

void And::validate() {
    
}

Result And::execute() {
    bool result {true};
    for(auto op : operands) {
        bool operand = std::get<1>(op);
        result = result && operand;
    }
    return result;
}

OptionSet And::options { "op", "ops" };

// Or

void Or::validate() {
    
}

Result Or::execute() {
    bool result {true};
    for(auto op : operands) {
        bool operand = std::get<1>(op);
        result = result || operand;
    }
    return result;
}

OptionSet Or::options { "op", "ops" };

// Xor

void Xor::validate() {
    
}

Result Xor::execute() {
    bool result {true};
    for(auto op : operands) {
        bool operand = std::get<1>(op);
        result = (!result && operand) || (!operand && result);
    }
    return result;
}

OptionSet Xor::options { "op", "ops" };

// Not

void Not::validate() {
    
}

Result Not::execute() {
    bool result = std::get<1>(operands[0]);
    return !result;
}

OptionSet Not::options { "op" };

/// Special commands

// Quit

void Quit::validate() {
    
}

Result Quit::execute() {
    std::exit(0);
}