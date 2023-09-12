#ifndef COMMAND_CONTROLLER_COMMAND_REGISTRY
#define COMMAND_CONTROLLER_COMMAND_REGISTRY

#include "ICommandRegistry.hpp"

class CommandRegistry : public ICommandRegistry {
public:
    CommandRegistry();
    virtual CommandPtr& findCommand(std::string) override;

private:
    void registerCommands();

private:
    Registry registry_;
};

#endif // COMMAND_CONTROLLER_COMMAND_REGISTRY