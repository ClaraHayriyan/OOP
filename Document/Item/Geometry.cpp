#include "Geometry.hpp"

#include <stdexcept>

Geometry::Geometry() {
    registerAttributes();
}

Geometry::Geometry(int tl_x, int tl_y, int br_x, int br_y) {
    reg_["TL_x"] = tl_x;
    reg_["TL_y"] = tl_y;
    reg_["BR_x"] = br_x;
    reg_["BR_y"] = br_y;
}

void Geometry::registerAttributes() {
    reg_["TL_x"] = 0;
    reg_["TL_y"] = 0;
    reg_["BR_x"] = 0;
    reg_["BR_y"] = 0;
}

void Geometry::set(std::string key, int value) {
    if(find(key))
        reg_[key] = value;
}

int Geometry::get(std::string key) const {
    if(!find(key))
        throw std::runtime_error("no such attribute exists!");
    auto it = reg_.find(key);
    return it->second;
}

bool Geometry::find(std::string key) const {
    auto it = reg_.find(key);
    if(it == reg_.end())
        return false;
    return true;
}