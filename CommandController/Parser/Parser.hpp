#ifndef COMMAND_CONTROLLER_PARSER_PARSER
#define COMMAND_CONTROLLER_PARSER_PARSER

#include "../Command/Command.hpp"
#include "../CommandRegistry/CommandRegistry.hpp"

#include <istream>

class Parser {
public:
    Parser(std::istream&);
    CommandPtr& parseCommand();

private:
    std::istream& input_;
    CommandRegistry commandRegistry_;
};

#endif // COMMAND_CONTROLLER_PARSER_PARSER
