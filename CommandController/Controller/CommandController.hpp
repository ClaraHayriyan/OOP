#ifndef COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER
#define COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER

#include "../Parser/Parser.hpp"
#include "../../Document/Document/Document.hpp"

#include <istream>

class CommandController {
public:
    CommandController(std::istream&);
    void run();

private:
    Parser parser_;
};

#endif // COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER