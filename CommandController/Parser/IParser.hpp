#ifndef COMMAND_CONTROLLER_PARSER_IPARSER
#define COMMAND_CONTROLLER_PARSER_IPARSER

#include <sstream>
#include <string>
#include <utility> // std::pair

using ParsingResult = std::pair<std::string, std::stringstream>;

class IParser {
public:
    virtual ParsingResult parseCommand(std::stringstream) =0;
};

#endif // COMMAND_CONTROLLER_PARSER_IPARSER