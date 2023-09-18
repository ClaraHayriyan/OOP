#ifndef COMMAND_CONTROLLER_INPUT_IINPUT
#define COMMAND_CONTROLLER_INPUT_IINPUT

#include <sstream>

class IInput {
public:
    virtual std::stringstream read() =0;
};

#endif // COMMAND_CONTROLLER_INPUT_IINPUT