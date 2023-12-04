#ifndef COMMAND_CONTROLLER_DOCUMENT_DOCUMENT
#define COMMAND_CONTROLLER_DOCUMENT_DOCUMENT

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

private:
    Slides::iterator find(int id);

private:
    Slides slides_;
    static int slideCount_;
};

#endif // COMMAND_CONTROLLER_DOCUMENT_DOCUMENT