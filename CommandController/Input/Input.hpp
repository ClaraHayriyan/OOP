#ifndef COMMAND_CONTROLLER_INPUT_INPUT
#define COMMAND_CONTROLLER_INPUT_INPUT

#include "IInput.hpp"

#include <sstream>

class Input : public IInput {
public:
    virtual std::stringstream read() override;
};

#endif // COMMAND_CONTROLLER_INPUT_INPUT