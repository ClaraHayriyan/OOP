#include "CommandController.hpp"

#include <iostream>

CommandController::CommandController(std::istream& input)
    : parser_{input}
{
}

void CommandController::exec() {
    while(true) {
        try {
           run(); 
        }
        catch (std::runtime_error err) {
            std::cout << err.what() << std::endl;
        }
    }
}

void CommandController::run() {
    CommandPtr commandPtr = parser_.parseCommand();
    commandPtr->execute(doc_);
}