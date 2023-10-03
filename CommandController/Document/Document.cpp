#include "Document.hpp"

#include <algorithm> // std::find_if

#include <iostream> ////// temporary

void Document::addItem(ItemPtr item) {
    ++itemCount_;
    item->setId(itemCount_);
    items_.push_back(std::move(item));
    std::cout << items_.back()->getId() << " " << items_.back()->getName() << " added!" << std::endl;
}

auto Document::getItem(int id) -> ItemPtr& {
    auto it = find(id);
    return *it;
}

void Document::removeItem(int id) {
    auto it = find(id);
    items_.erase(it);
}

auto Document::find(int id) -> Items::iterator {
    auto it = std::find_if(items_.begin(), items_.end(), 
                            [id](ItemPtr& item) {
                                return item->getId() == id;
                            });
    return it;
}

int Document::itemCount_ {0};