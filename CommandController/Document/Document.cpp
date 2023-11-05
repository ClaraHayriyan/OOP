#include "Document.hpp"

#include <algorithm> // std::find_if
#include <stdexcept> // std::runtime_error

#include <iostream> ////// temporary

void Document::addSlide() {
    ++slideCount_;
    slides_.emplace_back(slideCount_);
    std::cout << "slide " << slides_.back().getId() << " added!" << std::endl;
}

Slide& Document::getSlide(int id) {
    auto it = find(id);
    if(it == slides_.end())
        throw std::runtime_error("incorrect id!");
    return *it;
}

void Document::removeSlide(int id) {
    auto it = find(id);
    if(it == slides_.end())
        throw std::runtime_error("incorrect id!");
    Slide& slide = *it;
    std::cout << "slide " << slide.getId() << " removed!" << std::endl;
    slides_.erase(it);
}

auto Document::find(int id) -> Slides::iterator {
    auto it = std::find_if(slides_.begin(), slides_.end(), 
                            [id](Slide& slide) {
                                return slide.getId() == id;
                            });
    return it;
}

auto Document::begin() -> Slides::iterator {
    return slides_.begin();
}

auto Document::end() -> Slides::iterator {
    return slides_.end();
}

int Document::slideCount_ {0};