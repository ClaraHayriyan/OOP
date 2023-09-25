#include "Commands.hpp"

#include <cstdlib> // std::exit
#include <iostream>
#include <stdexcept> // std::runtime_error

// Add

Add::Add() {
    registerOptions();
}

void Add::registerOptions() {
    operandMap_["-op1"] = 0;
    operandMap_["-op2"] = 0;
}

void Add::addOperand(std::string option, double operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Add::execute() {
    double result {0};
    for(auto op : operandMap_)
        result += op.second;
    std::cout << result << std::endl;
}

Add* Add::create() {
    return new Add;
}

// Sub

Sub::Sub() {
    registerOptions();
}

void Sub::registerOptions() {
    operandMap_["-op1"] = 0;
    operandMap_["-op2"] = 0;
}

void Sub::addOperand(std::string option, double operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Sub::execute() {
    auto op = operandMap_.begin();
    double op2 {op->second};
    ++op;
    double op1 {op->second};
    std::cout << op1 - op2 << std::endl;
}

Sub* Sub::create() {
    return new Sub;
}

// Mul

Mul::Mul() {
    registerOptions();
}

void Mul::registerOptions() {
    operandMap_["-op1"] = 0;
    operandMap_["-op2"] = 0;
}

void Mul::addOperand(std::string option, double operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Mul::execute() {
    double result {1};
    for(auto op : operandMap_)
        result *= op.second;
    std::cout << result << std::endl;
}

Mul* Mul::create() {
    return new Mul;
}

// Div

Div::Div() {
    registerOptions();
}

void Div::registerOptions() {
    operandMap_["-op1"] = 0;
    operandMap_["-op2"] = 0;
}

void Div::addOperand(std::string option, double operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Div::execute() {
    auto op = operandMap_.begin();
    double op2 {op->second};
    ++op;
    double op1 {op->second};
    std::cout << op1 / op2 << std::endl;
}

Div* Div::create() {
    return new Div;
}

// Quit

void Quit::addOperand(std::string option, double operand) {
    throw std::runtime_error("invalid command!");
}

void Quit::execute() {
    std::exit(0);
}

Quit* Quit::create() {
    return new Quit;
}