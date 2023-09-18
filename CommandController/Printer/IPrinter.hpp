#ifndef COMMAND_CONTROLLER_PRINTER_IPRINTER
#define COMMAND_CONTROLLER_PRINTER_IPRINTER

#include <string>

class IPrinter {
public:
    virtual void output(std::string) =0;
};

#endif // COMMAND_CONTROLLER_PRINTER_IPRINTER