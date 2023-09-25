#include "CommandRegistry.hpp"
#include "../Command/Commands.hpp"

CommandRegistry::CommandRegistry() {
    registerCommands();
}

void CommandRegistry::registerCommands() {
    registry_["add"] = CommandPtr(new Add);
    registry_["sub"] = CommandPtr(new Sub);
    registry_["mul"] = CommandPtr(new Mul);
    registry_["div"] = CommandPtr(new Div);
    registry_["quit"] = CommandPtr(new Quit);
}

auto CommandRegistry::findCommand(std::string commandName) -> CommandPtr {
    auto iter = registry_.find(commandName);
    if(iter == registry_.end())
        return nullptr;
    return CommandPtr( iter->second->create() );
}

