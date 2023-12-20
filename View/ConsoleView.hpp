#ifndef OOP_VIEW_CONSOLE_VIEW_HPP
#define OOP_VIEW_CONSOLE_VIEW_HPP

#include "../Document/Document/Document.hpp"

#include <ostream>
#include <string_view>

class ConsoleView {
public:
    ConsoleView(std::ostream&);
    void display(const Document&);
    void display(const Slide&);
    void displayMessage(std::string_view message);

private:
    void display(const ItemPtr&);

private:
    std::ostream& ostream_;
};

#endif // OOP_VIEW_CONSOLE_VIEW_HPP