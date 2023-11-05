#include "Commands.hpp"
#include "../Item/Geometry.hpp"
#include "../Item/Attributes.hpp"

#include <cstdlib> // std::exit
#include <iostream>
#include <stdexcept> // std::runtime_error
#include <utility> // std::move

// AddItem

AddItem::AddItem() {
    registerOptions();
}

void AddItem::registerOptions() {
    operandMap_["slide"] = 0;
    operandMap_["name"] = "";
    operandMap_["TL_x"] = 0;
    operandMap_["TL_y"] = 0;
    operandMap_["BR_x"] = 0;
    operandMap_["BR_y"] = 0;
    operandMap_["fillColor"] = 0;
    operandMap_["lineColor"] = 0;
    operandMap_["lineWidth"] = 0;
}

void AddItem::addOperand(std::string option, OperandType operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    if(it->second.index() != operand.index())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void AddItem::execute(Document& doc) {
    Geometry geom(std::get<0>(operandMap_["TL_x"]), std::get<0>(operandMap_["TL_y"]),
                  std::get<0>(operandMap_["BR_x"]), std::get<0>(operandMap_["BR_y"]));
    Attributes attr(std::get<0>(operandMap_["lineWidth"]), std::get<0>(operandMap_["lineColor"]),
                    std::get<0>(operandMap_["fillColor"]));
    int slideId = std::get<0>(operandMap_["slide"]);
    Slide& slide = doc.getSlide(slideId);
    std::string name = std::get<1>(operandMap_["name"]);
    auto item = itemRegistry_.findItem(name);
    item->setGeometry(geom);
    item->setAttributes(attr);
    slide.addItem(std::move(item));
}

AddItem* AddItem::create() {
    return new AddItem;
}

// AddSlide

void AddSlide::addOperand(std::string option, OperandType operand) {
    throw std::runtime_error("invalid command!");
}

void AddSlide::execute(Document& doc) {
    doc.addSlide();
}

AddSlide* AddSlide::create() {
    return new AddSlide;
}


// Change

Change::Change() {
    registerOptions();
}

void Change::registerOptions() {
    operandMap_["slide"] = -1;
    operandMap_["id"] = -1;
    operandMap_["TL_x"] = -1;
    operandMap_["TL_y"] = -1;
    operandMap_["BR_x"] = -1;
    operandMap_["BR_y"] = -1;
    operandMap_["fillColor"] = -1;
    operandMap_["lineColor"] = -1;
    operandMap_["lineWidth"] = -1;
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
    int slideId = std::get<0>(operandMap_["slide"]);
    int id = std::get<0>(operandMap_["id"]);
    ItemPtr& item = doc.getSlide(slideId).getItem(id);

    for(auto op : operandMap_) {
        if(op.first == "id" || std::get<0>(op.second) == -1)
            continue;
        item->setPatameter(op.first, std::get<0>(op.second));
    }
}

Change* Change::create() {
    return new Change;
}

// RemoveItem

RemoveItem::RemoveItem() {
    registerOptions();
}

void RemoveItem::registerOptions() {
    operandMap_["slide"] = -1;
    operandMap_["id"] = -1;
}

void RemoveItem::addOperand(std::string option, OperandType operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    if(it->second.index() != operand.index())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void RemoveItem::execute(Document& doc) {
    int slideId = std::get<0>(operandMap_["slide"]);
    int id = std::get<0>(operandMap_["id"]);
    doc.getSlide(slideId).removeItem(id);
}

RemoveItem* RemoveItem::create() {
    return new RemoveItem;
}

// RemoveSlide


RemoveSlide::RemoveSlide() {
    registerOptions();
}

void RemoveSlide::registerOptions() {
    operandMap_["slide"] = -1;
}

void RemoveSlide::addOperand(std::string option, OperandType operand) {
    auto it = operandMap_.find(option);
    if(it == operandMap_.end())
        throw std::runtime_error("invalid command!");
    if(it->second.index() != operand.index())
        throw std::runtime_error("invalid command!");
    operandMap_[option] = operand;
}

void RemoveSlide::execute(Document& doc) {
    int slideId = std::get<0>(operandMap_["slide"]);
    doc.removeSlide(slideId);
}

RemoveSlide* RemoveSlide::create() {
    return new RemoveSlide;
}

// Display

Display::Display() {
    registerOptions();
}

void Display::registerOptions() {
    operandMap_["slide"] = -1;
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
    int slideId = std::get<0>(operandMap_["slide"]);
    if(slideId >= 0) {
        Slide& slide = doc.getSlide(slideId);
        for(auto& it : slide) {
            std::cout << it->getId() << " " << it->getName() << std::endl;
        }
        return;
    }
    for(auto& it : doc) {
        std::cout << "slide " << it.getId() << std::endl;
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