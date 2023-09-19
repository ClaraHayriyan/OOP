#include "CommandController.hpp"

#include <iostream>
#include <utility> // std::move

CommandController::CommandController(std::istream& input, PrinterPtr printer)
    : parser_{input}
    , printer_{std::move(printer)}
{
}

void CommandController::exec() {
    while(true) {
        try {
           run(); 
        }
        catch (std::runtime_error err) {
            printer_->output(err.what());
        }
    }
}

void CommandController::run() {
    CommandPtr& commandPtr = parser_.parseCommand();
    auto result = commandPtr->execute();
    commandPtr->reset();
    printer_->output(result);
}