#include "Controller/CommandController.hpp"
#include "Input/Input.hpp"
#include "Parser/Parser.hpp"
#include "CommandRegistry/CommandRegistry.hpp"
#include "Printer/Printer.hpp"

#include <memory> // std::make_unique

int main() {
    CommandController controller{std::make_unique<Input>(), std::make_unique<Parser>(),
                                 std::make_unique<CommandRegistry>(), std::make_unique<Printer>()};
    controller.exec();
}

