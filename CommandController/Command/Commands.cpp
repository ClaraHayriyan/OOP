#include "Commands.hpp"

#include <cstdlib> // std::exit
#include <iostream>
#include <stdexcept> // std::runtime_error
#include <utility> // std::move

// Add

Add::Add() {
    registerOptions();
}

void Add::registerOptions() {
    operandMap_["-name"] = "";
    operandMap_["-TL"] = 0;
    operandMap_["-BR"] = 0;
    operandMap_["-fillColor"] = 0;
    operandMap_["-lineColor"] = 0;
    operandMap_["-lineWidth"] = 0;
}

void Add::addOperand(std::string option, OperandType operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    if(it->second.index() != operand.index())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Add::execute(Document& doc) {
    std::string name = std::get<1>(operandMap_["-name"]);
    auto item = itemRegistry_.findItem(name);
    if(!item)
        throw std::runtime_error("invalid item name!");
    for(auto op : operandMap_) {
        if(op.first == "-name")
            continue;
        item->setPatameter(op.first, std::get<0>(op.second));
    }
    doc.addItem(std::move(item));
}

Add* Add::create() {
    return new Add;
}

// Change

Change::Change() {
    registerOptions();
}

void Change::registerOptions() {
    operandMap_["-id"] = -1;
    operandMap_["-TL"] = -1;
    operandMap_["-BR"] = -1;
    operandMap_["-fillColor"] = -1;
    operandMap_["-lineColor"] = -1;
    operandMap_["-lineWidth"] = -1;
}

void Change::addOperand(std::string option, OperandType operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    if(it->second.index() != operand.index())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Change::execute(Document& doc) {
    int id = std::get<0>(operandMap_["-id"]);
    ItemPtr& item = doc.getItem(id);

    for(auto op : operandMap_) {
        if(op.first == "-id" || std::get<0>(op.second) == -1)
            continue;
        item->setPatameter(op.first, std::get<0>(op.second));
    }
}

Change* Change::create() {
    return new Change;
}

// Remove

Remove::Remove() {
    registerOptions();
}

void Remove::registerOptions() {
    operandMap_["-id"] = -1;
}

void Remove::addOperand(std::string option, OperandType operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    if(it->second.index() != operand.index())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Remove::execute(Document& doc) {
    int id = std::get<0>(operandMap_["-id"]);
    doc.removeItem(id);
}

Remove* Remove::create() {
    return new Remove;
}

// Display

Display::Display() {
    registerOptions();
}

void Display::registerOptions() {
    operandMap_["-id"] = -1;
}

void Display::addOperand(std::string option, OperandType operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    if(it->second.index() != operand.index())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void Display::execute(Document& doc) {
    int id = std::get<0>(operandMap_["-id"]);
    if(id >= 0) {
        ItemPtr& item = doc.getItem(id);
        std::cout << item->getId() << " " << item->getName() << " " << item->getParams() << std::endl;
        return;
    }
    for(auto& it : doc) {
        std::cout << it->getId() << " " << it->getName() << std::endl;
    }
}

Display* Display::create() {
    return new Display;
}


// Quit

void Quit::addOperand(std::string option, OperandType operand) {
    throw std::runtime_error("invalid command!");
}

void Quit::execute(Document&) {
    std::exit(0);
}

Quit* Quit::create() {
    return new Quit;
}