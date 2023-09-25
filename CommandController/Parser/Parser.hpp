#ifndef COMMAND_CONTROLLER_PARSER_PARSER
#define COMMAND_CONTROLLER_PARSER_PARSER

#include "../Command/Command.hpp"
#include "../CommandRegistry/CommandRegistry.hpp"

#include <istream>
#include <sstream>

class Parser {
public:
    Parser(std::istream&);
    CommandPtr parseCommand();

private:
   std::stringstream inputCommand(); 

private:
    std::istream& input_;
    CommandRegistry commandRegistry_;
};

#endif // COMMAND_CONTROLLER_PARSER_PARSER
