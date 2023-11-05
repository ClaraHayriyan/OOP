#include "CommandRegistry.hpp"
#include "../Command/Commands.hpp"

CommandRegistry::CommandRegistry() {
    registerCommands();
}

void CommandRegistry::registerCommands() {
    registry_["addItem"] = CommandPtr(new AddItem);
    registry_["addSlide"] = CommandPtr(new AddSlide);
    registry_["change"] = CommandPtr(new Change);
    registry_["removeItem"] = CommandPtr(new RemoveItem);
    registry_["removeSlide"] = CommandPtr(new RemoveSlide);
    registry_["display"] = CommandPtr(new Display);
    registry_["quit"] = CommandPtr(new Quit);
}

auto CommandRegistry::findCommand(std::string commandName) -> CommandPtr {
    auto iter = registry_.find(commandName);
    if(iter == registry_.end())
        return nullptr;
    return CommandPtr( iter->second->create() );
}

