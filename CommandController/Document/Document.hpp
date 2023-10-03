#ifndef COMMAND_CONTROLLER_DOCUMENT_DOCUMENT
#define COMMAND_CONTROLLER_DOCUMENT_DOCUMENT

#include "../Item/Item.hpp"

#include <memory> // std::unique_ptr
#include <string>
#include <unordered_map>
#include <vector>

using ItemPtr = std::unique_ptr<Item>;

class Document {
public:
    void addItem(ItemPtr item);
    ItemPtr& getItem(int id);
    void removeItem(int id);

private:
    using Items = std::vector<ItemPtr>;

public:
    Items::iterator begin();
    Items::iterator end();

private:
    Items::iterator find(int id);

private:
    Items items_;
    static int itemCount_;
};

#endif // COMMAND_CONTROLLER_DOCUMENT_DOCUMENT