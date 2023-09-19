#ifndef COMMAND_CONTROLLER_PARSER_IPARSER
#define COMMAND_CONTROLLER_PARSER_IPARSER

#include "../Command/Command.hpp"
#include "../CommandRegistry/CommandRegistry.hpp"

#include <string>
#include <utility> // std::pair

class IParser {
public:
    virtual CommandPtr& parseCommand() =0;
};

#endif // COMMAND_CONTROLLER_PARSER_IPARSER