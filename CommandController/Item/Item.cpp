#include "Item.hpp"

#include <sstream>
#include <stdexcept> // std::runtime_error

Item::Item() {
    registerParams();
}

void Item::registerParams() {
    params_["-TL"] = 0;
    params_["-BR"] = 0;
    params_["-fillColor"] = 0;
    params_["-lineColor"] = 0;
    params_["-lineWidth"] = 0;
}

void Item::setId(int id) {
    id_ = id;
}

void Item::setPatameter(std::string key, int value) {
    auto it = params_.find(key);
    if(it == params_.end())
        throw std::runtime_error("invalid parameter for an object!");
    params_[key] = value;
}

int Item::getId() const {
    return id_;
}

std::string Item::getParams() const {
    std::stringstream stream;
    for(auto it : params_) {
        stream << it.first << " " << it.second << " ";
    }
    return stream.str();
}