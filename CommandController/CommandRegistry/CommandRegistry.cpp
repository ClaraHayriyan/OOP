#include "CommandRegistry.hpp"
#include "../Command/Command.hpp"

CommandRegistry::CommandRegistry() {
    registerCommands();
}

void CommandRegistry::registerCommands() {
    registry_["ADD"] = CommandPtr(new Add);
    registry_["SUB"] = CommandPtr(new Sub);
    registry_["MUL"] = CommandPtr(new Mul);
    registry_["DIV"] = CommandPtr(new Div);
    registry_["AND"] = CommandPtr(new And);
    registry_["OR"] = CommandPtr(new Or);
    registry_["XOR"] = CommandPtr(new Xor);
    registry_["NOT"] = CommandPtr(new Not);
    registry_["QUIT"] = CommandPtr(new Quit);
}

auto CommandRegistry::findCommand(std::string commandName) -> CommandPtr& {
    auto iter = registry_.find(commandName);
    if(iter == registry_.end())
        throw std::runtime_error("invalid command!");
    return iter->second;
}

