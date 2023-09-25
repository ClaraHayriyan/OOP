#include "Parser.hpp"

#include <stdexcept> // std::runtime_error
#include <string>
#include <utility> // std::move

Parser::Parser(std::istream& input)
: input_{input}
{
}

std::stringstream Parser::inputCommand() {
    std::string command;
    getline(input_, command);
    return std::stringstream(command);
}

CommandPtr Parser::parseCommand() {

    std::stringstream stream = inputCommand();

    std::string token;
    double op;                  // op type is double yet

    stream >> token;

    CommandPtr commandPtr = commandRegistry_.findCommand(token);
    if(!commandPtr)
        throw std::runtime_error("invalid command!");

    while(stream >> token) {
            stream >> op;
            commandPtr->addOperand(token, op);
    }
    return commandPtr;
}
