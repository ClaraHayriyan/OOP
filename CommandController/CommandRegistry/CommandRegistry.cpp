#include "CommandRegistry.hpp"
#include "../Command/Commands.hpp"

CommandRegistry::CommandRegistry() {
    registerCommands();
}

void CommandRegistry::registerCommands() {
    registry_["add"] = CommandPtr(new Add);
    registry_["change"] = CommandPtr(new Change);
    registry_["remove"] = CommandPtr(new Remove);
    registry_["display"] = CommandPtr(new Display);
    registry_["quit"] = CommandPtr(new Quit);
}

auto CommandRegistry::findCommand(std::string commandName) -> CommandPtr {
    auto iter = registry_.find(commandName);
    if(iter == registry_.end())
        return nullptr;
    return CommandPtr( iter->second->create() );
}

