#ifndef OOP_COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER_HPP
#define OOP_COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER_HPP

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

#endif // OOP_COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER_HPP