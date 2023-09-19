#include "Command.hpp"

void Command::addOperand(OperandType operand) {
    operands.push_back(operand);
}

void Command::reset() {
    operands.clear();
}