#include "Item.hpp"

#include <sstream>
#include <stdexcept> // std::runtime_error

/*
Item::Item(int id, Geometry geom, Attributes attr)
: id_{id}
, geometry_{geom}
, attributes_{attr}
{
}
*/
void Item::setId(int id) {
    id_ = id;
}

void Item::setGeometry(const Geometry& geom) {
    geometry_ = geom;
}

void Item::setAttributes(const Attributes& attr) {
    attributes_ = attr;
}

void Item::setPatameter(std::string key, int value) {
    if(geometry_.find(key)) {
        geometry_.set(key, value);
        return;
    }
    if(attributes_.find(key)) {
        attributes_.set(key, value);
        return;
    }
    throw std::runtime_error("invalid parameter for an object!");
}

int Item::getParameter(std::string key) const {
    if(geometry_.find(key))
        return geometry_.get(key);
    if(attributes_.find(key))
        return attributes_.get(key);
    throw std::runtime_error("no such parameter exists!");
}

int Item::getId() const {
    return id_;
}