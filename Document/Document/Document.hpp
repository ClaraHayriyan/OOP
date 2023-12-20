#ifndef OOP_DOCUMENT_DOCUMENT_DOCUMENT_HPP
#define OOP_DOCUMENT_DOCUMENT_DOCUMENT_HPP

#include "../Slide/Slide.hpp"

#include <vector>

class Document {
public:
    void addSlide();
    Slide& getSlide(int id);
    void removeSlide(int id);

private:
    using Slides = std::vector<Slide>;

public:
    Slides::iterator begin();
    Slides::iterator end();
    Slides::const_iterator begin() const;
    Slides::const_iterator end() const;

private:
    Slides::iterator find(int id);

private:
    Slides slides_;
    static int slideCount_;
};

#endif // OOP_DOCUMENT_DOCUMENT_DOCUMENT_HPP