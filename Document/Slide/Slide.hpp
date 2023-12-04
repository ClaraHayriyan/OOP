#ifndef OOP_DOCUMENT_SLIDE_SLIDE_HPP
#define OOP_DOCUMENT_SLIDE_SLIDE_HPP

#include "../Item/Item.hpp"

#include <memory> // std::unique_ptr
#include <vector>

using ItemPtr = std::unique_ptr<Item>;

class Slide {
public:
    Slide(int id);
    void addItem(ItemPtr item);
    int getId() const;
    ItemPtr& getItem(int id);
    int getItemCount() const;
    void removeItem(int id);

private:
    using Items = std::vector<ItemPtr>;

public:
    Items::iterator begin();
    Items::iterator end();

private:
    Items::iterator find(int id);

private:
    int id_;
    Items items_;
    static int itemCount_;
};

#endif // OOP_DOCUMENT_SLIDE_SLIDE_HPP