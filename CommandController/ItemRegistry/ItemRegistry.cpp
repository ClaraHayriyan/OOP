
#include "ItemRegistry.hpp"
#include "../../Document/Item/Items.hpp"

ItemRegistry::ItemRegistry() {
    registerItems();
}

void ItemRegistry::registerItems() {
    registry_["line"] = ItemPtr(new Line);
    registry_["rectangle"] = ItemPtr(new Rectangle);
    registry_["ellipse"] = ItemPtr(new Ellipse);
    registry_["triangle"] = ItemPtr(new Triangle);
    registry_["table"] = ItemPtr(new Table);
    registry_["rhombus"] = ItemPtr(new Rhombus);
}

auto ItemRegistry::findItem(std::string name) -> ItemPtr {
    auto iter = registry_.find(name);
    if(iter == registry_.end())
        return nullptr;
    return ItemPtr( iter->second->create() );
}

