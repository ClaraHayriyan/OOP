
#include "ItemRegistry.hpp"
#include "../../Document/Item/Items.hpp"

#include <stdexcept> // std::runtime_error

ItemRegistry::ItemRegistry() {
    registerItems();
}

void ItemRegistry::registerItems() {
    registry_["line"] = ItemPtr(new Line);
    registry_["rectangle"] = ItemPtr(new Rectangle);
    registry_["ellipse"] = ItemPtr(new Ellipse);
    registry_["triangle"] = ItemPtr(new Triangle);
    registry_["trapezoid"] = ItemPtr(new Trapezoid);
    registry_["rhombus"] = ItemPtr(new Rhombus);
}

auto ItemRegistry::findItem(std::string name) -> ItemPtr {
    auto iter = registry_.find(name);
    if(iter == registry_.end())
        throw std::runtime_error("no such item exists!");
    return ItemPtr( iter->second->create() );
}

