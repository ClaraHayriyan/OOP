#ifndef COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER
#define COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER

#include "../Parser/Parser.hpp"
#include "../Document/Document.hpp"

#include <istream>

class CommandController {
public:
    CommandController(std::istream&);
    void exec();

private:
    void run();

private:
    Parser parser_;
    Document doc_;
};

#endif // COMMAND_CONTROLLER_CONTROLLER_COMMAND_CONTROLLER