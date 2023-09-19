#include "Parser.hpp"

#include <stdexcept> // std::runtime_error
#include <utility> // std::move

Parser::Parser(std::istream& input)
: input_{input}
{
}

CommandPtr& Parser::parseCommand() {
    std::string token;
    Result op;

    input_ >> token;

    CommandPtr& commandPtr = commandRegistry_.findCommand(token);

    while(input_ >> token) {
        if(token[0] == '-') {
            input_ >> op;
            commandPtr->addOperand({token, op});
        } else
            throw std::runtime_error("invalid command!");
    }
    return commandPtr;
}
