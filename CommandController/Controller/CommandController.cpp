#include "CommandController.hpp"

CommandController::CommandController(std::istream& input)
    : parser_{input}
{
}

void CommandController::run() {
    CommandPtr commandPtr = parser_.parseCommand();
    commandPtr->execute();
}