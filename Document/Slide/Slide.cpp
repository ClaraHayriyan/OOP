#include "Slide.hpp"

#include <algorithm> // std::find_if
#include <stdexcept> // std::runtime_error

#include <iostream> ////// temporary

Slide::Slide(int id)
: id_{id}
{
}

void Slide::addItem(ItemPtr item) {
    ++itemCount_;
    item->setId(itemCount_);
    items_.push_back(std::move(item));
    std::cout << items_.back()->getName() << " " << items_.back()->getId() << " added!" << std::endl;
}

int Slide::getId() const {
    return id_;
}

auto Slide::getItem(int id) -> ItemPtr& {
    auto it = find(id);
    if(it == items_.end())
        throw std::runtime_error("incorrect id!");
    return *it;
}

int Slide::getItemCount() const {
    return itemCount_;
}

void Slide::removeItem(int id) {
    auto it = find(id);
    if(it == items_.end())
        throw std::runtime_error("incorrect id!");
    ItemPtr& item = *it;
    std::cout << item->getName() << " " << item->getId() << " removed!" << std::endl;
    items_.erase(it);
}

auto Slide::find(int id) -> Items::iterator {
    auto it = std::find_if(items_.begin(), items_.end(), 
                            [id](ItemPtr& item) {
                                return item->getId() == id;
                            });
    return it;
}

auto Slide::begin() -> Items::iterator {
    return items_.begin();
}

auto Slide::end() -> Items::iterator {
    return items_.end();
}

int Slide::itemCount_ {0};