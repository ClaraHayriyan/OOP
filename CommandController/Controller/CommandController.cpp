#include "CommandController.hpp"

CommandController::CommandController(std::istream& input)
    : parser_{input}
{
}

void CommandController::run() {
    // TK: get you input nline here and pass istrim to parser, you do not need to keep parser as a memeber, you can simply create parser instance as local variable right here
    CommandPtr commandPtr = parser_.parseCommand();
    commandPtr->execute();
}
