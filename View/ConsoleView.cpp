#include "ConsoleView.hpp"

ConsoleView::ConsoleView(std::ostream& ostream)
: ostream_{ostream}
{
}

void ConsoleView::display(const Document& doc) {
    for(const auto& slide : doc) {
        display(slide);
    }

}

void ConsoleView::display(const Slide& slide) {
    ostream_ << "Slide " << slide.getId() << std::endl;
    for(const auto& item : slide) {
        display(item);
    }
}

void ConsoleView::displayMessage(std::string_view message) {
    ostream_ << message << std::endl;
}

void ConsoleView::display(const ItemPtr& item) {
    
    ostream_ << '\t' << item->getId() << " " << item->getName() << std::endl;
    ostream_ << "\t\t"
             << "TL_x: " << item->getParameter("TL_x") << " TL_y: " << item->getParameter("TL_y")
             << " BR_x: " << item->getParameter("BR_x") << " BR_y: " << item->getParameter("BR_y") << std::endl;
    ostream_ << "\t\t"
             << "lineWidth: " << item->getParameter("lineWidth") << " lineColor: " << item->getParameter("lineColor")
             << " fillColor: " << item->getParameter("fillColor") <<  std::endl;
}