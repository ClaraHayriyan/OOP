#ifndef COMMAND_CONTROLLER_INPUT
#define COMMAND_CONTROLLER_INPUT

#include "IInput.hpp"

#include <sstream>

class Input : public IInput {
public:
    virtual std::stringstream read() override;
};

#endif // COMMAND_CONTROLLER_INPUT