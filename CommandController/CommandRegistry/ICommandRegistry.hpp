#ifndef COMMAND_CONTROLLER_COMMAND_REGISTRY_ICOMMAND_REGISTRY
#define COMMAND_CONTROLLER_COMMAND_REGISTRY_ICOMMAND_REGISTRY

#include "../Command/Command.hpp"

#include <memory> // std::uniqe_ptr
#include <string>
#include <unordered_map>

using CommandPtr = std::unique_ptr<Command>;

class ICommandRegistry {
protected:
    using Registry = std::unordered_map<std::string, CommandPtr>;

public:
    virtual CommandPtr& findCommand(std::string) =0;
};

#endif // COMMAND_CONTROLLER_COMMAND_REGISTRY_ICOMMAND_REGISTRY