#include "Controller/CommandController.hpp"

#include <iostream>

int main() {
    CommandController controller{std::cin};
    controller.exec();
}
