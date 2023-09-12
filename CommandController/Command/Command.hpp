#ifndef COMMAND_CONTROLLER_COMMAND
#define COMMAND_CONTROLLER_COMMAND

#include "ICommand.hpp"

class Add : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class Sub : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class Mul : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class Div : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class And : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class Or : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class Xor : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class Not : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

class Quit : public ICommand {
public:
    virtual std::string execute(std::stringstream args) override;
};

#endif // COMMAND_CONTROLLER_COMMAND
