#ifndef COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER
#define COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER

#include "../Input/IInput.hpp"
#include "../Parser/IParser.hpp"
#include "../CommandRegistry/ICommandRegistry.hpp"
#include "../Printer/IPrinter.hpp"

#include <memory> // std::unique_ptr

class CommandController {
private:
    using InputPtr = std::unique_ptr<IInput>;
    using ParserPtr = std::unique_ptr<IParser>;
    using CommandRegistryPtr = std::unique_ptr<ICommandRegistry>;
    using PrinterPtr = std::unique_ptr<IPrinter>;

public:
    CommandController(InputPtr, ParserPtr, CommandRegistryPtr, PrinterPtr);
    void exec();

private:
    void run();

private:
    InputPtr input_;
    ParserPtr parser_;
    CommandRegistryPtr commandRegistry_;
    PrinterPtr printer_;
};

#endif // COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER