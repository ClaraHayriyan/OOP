#ifndef OOP_DOCUMENT_SLIDE_SLIDE_HPP
#define OOP_DOCUMENT_SLIDE_SLIDE_HPP

#include "../Item/Item.hpp"

#include <memory> // std::unique_ptr
#include <vector>

using ItemId = int;

using ItemPtr = std::unique_ptr<Item>;

class Slide {
public:
    Slide(int id);
    // TK: Reorganize your methods order like this to impoove readability
    int getId() const; // Returns slide it, but it is better to get rid of slide Id, keep only Item ids, and slide could be identifed by its top/group item

    // Access/Iterate  items
    int getItemCount() const; // TK: use size_t instead of int
    Item const& getItem(ItemId id); // TK: you shouldn't return reference to unique pointer, better to return reference of the item, but not good solution either, you need to rely on iterators, make your find a public method and remove those methods
    ItemId getItemId(int index) const; // TK: if you have getItemCount & getItem methods you need also this method as well for the sake of completness
    // 

    // Add/Remove items
    void addItem(ItemPtr item);
    void removeItem(ItemId id);

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
    static int itemCount_; // TK: not a good solution
};

#endif // OOP_DOCUMENT_SLIDE_SLIDE_HPP
