#ifndef COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER
#define COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER

#include "../Parser/Parser.hpp"
#include "../Printer/IPrinter.hpp"

#include <istream>
#include <memory> // std::unique_ptr

class CommandController {
private:
    using PrinterPtr = std::unique_ptr<IPrinter>;

public:
    CommandController(std::istream&, PrinterPtr);
    void exec();

private:
    void run();

private:
    Parser parser_;
    PrinterPtr printer_;
};

#endif // COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER