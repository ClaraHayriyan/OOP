#ifndef COMMAND_CONTROLLER_COMMAND_REGISTRY_COMMAND_REGISTRY
#define COMMAND_CONTROLLER_COMMAND_REGISTRY_COMMAND_REGISTRY

#include "../Command/Command.hpp"

#include <memory> // std::uniqe_ptr
#include <string>
#include <unordered_map>

using CommandPtr = std::unique_ptr<Command>;

class CommandRegistry {
public:
    CommandRegistry();
    CommandPtr findCommand(std::string);

private:
    void registerCommands();

private:
    using Registry = std::unordered_map<std::string, CommandPtr>;

private:
    Registry registry_;
};

#endif // COMMAND_CONTROLLER_COMMAND_REGISTRY_COMMAND_REGISTRY