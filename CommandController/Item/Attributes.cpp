#include "Attributes.hpp"

#include <stdexcept>

Attributes::Attributes() {
    registerAttributes();
}

Attributes::Attributes(int lineWidth, int lineColor, int fillColor) {
    reg_["lineWidth"] = lineWidth;
    reg_["lineColor"] = lineColor;
    reg_["fillColor"] = fillColor;
}

void Attributes::registerAttributes() {
    reg_["lineWidth"] = 0;
    reg_["lineColor"] = 0;
    reg_["fillColor"] = 0;
}

void Attributes::set(std::string key, int value) {
    if(find(key))
        reg_[key] = value;
}

int Attributes::get(std::string key) const {
    if(!find(key))
        throw std::runtime_error("no such attribute exists!");
    auto it = reg_.find(key);
    return it->second;
}

bool Attributes::find(std::string key) const {
    auto it = reg_.find(key);
    if(it == reg_.end())
        return false;
    return true;
}