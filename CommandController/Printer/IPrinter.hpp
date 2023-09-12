#ifndef COMMAND_CONTROLLER_IPRINTER
#define COMMAND_CONTROLLER_IPRINTER

#include <string>

class IPrinter {
public:
    virtual void output(std::string) =0;
};

#endif // COMMAND_CONTROLLER_IPRINTER