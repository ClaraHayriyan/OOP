#include "CommandController.hpp"

#include <iostream>
#include <utility> // std::move

CommandController::CommandController(InputPtr input, ParserPtr parser, CommandRegistryPtr commandRegistry, PrinterPtr printer)
    : input_{std::move(input)}
    , parser_{std::move(parser)}
    , commandRegistry_{std::move(commandRegistry)}
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
    auto inputStream = input_->read();
    auto [commandName, args] = parser_->parseCommand(std::move(inputStream));
    if(commandName.empty())
        return;
    auto& command = commandRegistry_->findCommand(commandName);
    auto result = command->execute(std::move(args));
    printer_->output(result);
}