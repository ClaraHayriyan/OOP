#ifndef COMMAND_CONTROLLER_COMMAND_ICOMMAND
#define COMMAND_CONTROLLER_COMMAND_ICOMMAND

#include <sstream>
#include <string>

class ICommand {
public:
    virtual std::string execute(std::stringstream args) =0;
};

#endif // COMMAND_CONTROLLER_COMMAND_ICOMMAND
