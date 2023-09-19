#ifndef COMMAND_CONTROLLER_PRINTER_IPRINTER
#define COMMAND_CONTROLLER_PRINTER_IPRINTER

#include <string>

using Result = double;

class IPrinter {
public:
    virtual void output(Result) =0;
    virtual void output(std::string) =0;
};

#endif // COMMAND_CONTROLLER_PRINTER_IPRINTER