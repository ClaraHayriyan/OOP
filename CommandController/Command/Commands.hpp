#ifndef COMMAND_CONTROLLER_COMMAND_COMMAND
#define COMMAND_CONTROLLER_COMMAND_COMMAND

#include "Command.hpp"

#include <string>
#include <unordered_set>

using OptionSet = std::unordered_set<std::string>;

// Arithmetic commands

class Add : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

class Sub : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

class Mul : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

class Div : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

// Logical commands

class And : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

class Or : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

class Xor : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

class Not : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;

private:
    static OptionSet options;
};

// Special commands

class Quit : public Command {
public:
    virtual void validate() override;
    virtual Result execute() override;
};

#endif // COMMAND_CONTROLLER_COMMAND_COMMAND
