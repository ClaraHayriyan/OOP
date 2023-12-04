#ifndef COMMAND_CONTROLLER_COMMAND_ICOMMAND
#define COMMAND_CONTROLLER_COMMAND_ICOMMAND

#include "../../Document/Document/Document.hpp"

#include <string>
#include <unordered_map>
#include <variant>

using OperandType = std::variant<int, std::string>;
using OperandMap = std::unordered_map<std::string, OperandType>;

class Command {
public:
    virtual void addOperand(std::string option, OperandType operand) =0;
    virtual void execute(Document& doc) =0;
    virtual Command* create() =0;
    virtual ~Command() =default;

protected:
    OperandMap operandMap_;
};

#endif // COMMAND_CONTROLLER_COMMAND_ICOMMAND
