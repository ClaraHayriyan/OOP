#ifndef COMMAND_CONTROLLER_ICOMMAND_REGISTRY
#define COMMAND_CONTROLLER_ICOMMAND_REGISTRY

#include "../Command/ICommand.hpp"

#include <memory> // std::uniqe_ptr
#include <string>
#include <unordered_map>

class ICommandRegistry {
protected:
    using CommandPtr = std::unique_ptr<ICommand>;
    using Registry = std::unordered_map<std::string, CommandPtr>;

public:
    virtual CommandPtr& findCommand(std::string) =0;
};

#endif // COMMAND_CONTROLLER_ICOMMAND_REGISTRY