#ifndef COMMAND_CONTROLLER_PARSER
#define COMMAND_CONTROLLER_PARSER

#include "IParser.hpp"

class Parser : public IParser {
public:
    virtual ParsingResult parseCommand(std::stringstream) override;
};

#endif // COMMAND_CONTROLLER_PARSER
