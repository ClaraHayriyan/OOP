#include "Parser.hpp"

#include <stdexcept>
#include <utility> // std::move

ParsingResult Parser::parseCommand(std::stringstream inputStream) {
    std::stringstream args;
    std::string command;
    std::string token;

    inputStream >> command;
    if(!(inputStream >> token))
        return {command, std::move(args)};
        
    if(token == "-args") {
        while(inputStream >> token)
            args << token << " ";
    } else if(token == "-arg1") {
        inputStream >> token;
        args << token << " ";
        inputStream >> token;
        if(token != "-arg2")
            throw std::runtime_error("invalid command!");
        inputStream >> token;
        args << token << " ";
    } else if(token == "-arg") {
        inputStream >> token;
        args << token << " ";
    } else
        throw std::runtime_error("invalid command!");
    return {command, std::move(args)};
}
