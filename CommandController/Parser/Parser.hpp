#ifndef OOP_COMMAND_CONTROLLER_PARSER_PARSER_HPP
#define OOP_COMMAND_CONTROLLER_PARSER_PARSER_HPP

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
    CommandRegistry commandRegistry_; // TK:  Command registry doesn't belongs to Parsr, parser should get commands registry in its constructor
};

#endif // OOP_COMMAND_CONTROLLER_PARSER_PARSER_HPP
