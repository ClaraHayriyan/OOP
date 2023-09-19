#ifndef COMMAND_CONTROLLER_COMMAND_ICOMMAND
#define COMMAND_CONTROLLER_COMMAND_ICOMMAND

#include <sstream>
#include <string>
#include <utility> // std::pair
#include <vector>

using OperandType = std::pair<std::string, double>;
using Result = double;

class Command {
public:
    void addOperand(OperandType operand);
    void reset();
    virtual void validate() =0;
    virtual Result execute() =0;
    virtual ~Command() {}
    
protected:
    std::vector<OperandType> operands;
};

#endif // COMMAND_CONTROLLER_COMMAND_ICOMMAND
