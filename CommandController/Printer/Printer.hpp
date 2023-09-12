#ifndef COMMAND_CONTROLLER_PRINTER
#define COMMAND_CONTROLLER_PRINTER

#include "IPrinter.hpp"

#include <string>

class Printer : public IPrinter {
public:
    virtual void output(std::string) override;
};

#endif // COMMAND_CONTROLLER_PRINTER