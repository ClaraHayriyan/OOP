#include "Controller/CommandController.hpp"
#include "Input/Input.hpp"
#include "Printer/Printer.hpp"
#include "Controller/CommandController.hpp"

#include <iostream>
#include <memory> // std::make_unique

int main() {
    CommandController controller{std::cin, std::make_unique<Printer>()};
    controller.exec();
}
