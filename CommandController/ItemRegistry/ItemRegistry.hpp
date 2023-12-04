#ifndef OOP_COMMAND_CONTROLLER_ITEM_REGISTRY_ITEM_REGISTRY_HPP
#define OOP_COMMAND_CONTROLLER_ITEM_REGISTRY_ITEM_REGISTRY_HPP

#include "../../Document/Item/Item.hpp"

#include <memory> // std::unique_ptr
#include <string>
#include <unordered_map>

using ItemPtr = std::unique_ptr<Item>;

class ItemRegistry {
public:
    ItemRegistry();
    ItemPtr findItem(std::string name);

private:
    void registerItems();

private:
    using Registry = std::unordered_map<std::string, ItemPtr>;

private:
    Registry registry_;
};

#endif // OOP_COMMAND_CONTROLLER_ITEM_REGISTRY_ITEM_REGISTRY_HPP