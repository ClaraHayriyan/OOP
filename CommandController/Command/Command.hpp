#ifndef OOP_COMMAND_CONTROLLER_COMMAND_COMMAND_HPP
#define OOP_COMMAND_CONTROLLER_COMMAND_COMMAND_HPP

#include <string>
#include <unordered_map>
#include <variant>

using OperandType = std::variant<int, std::string>;
using OperandMap = std::unordered_map<std::string, OperandType>;

class Command {
public:
    virtual void addOperand(std::string option, OperandType operand) =0;
    virtual void execute() =0;
    virtual Command* create() =0;
    virtual ~Command() =default;

protected:
    OperandMap operandMap_;
};

#endif // OOP_COMMAND_CONTROLLER_COMMAND_COMMAND_HPP
