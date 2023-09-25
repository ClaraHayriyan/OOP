#ifndef COMMAND_CONTROLLER_COMMAND_COMMAND
#define COMMAND_CONTROLLER_COMMAND_COMMAND

#include "Command.hpp"

class Add : public Command {
public:
    Add();
    virtual void addOperand(std::string option, double operand) override;
    virtual void execute() override;
    virtual Add* create() override;

private:
    void registerOptions();
};

class Sub : public Command {
public:
    Sub();
    virtual void addOperand(std::string option, double operand) override;
    virtual void execute() override;
    virtual Sub* create() override;

private:
    void registerOptions();
};

class Mul : public Command {
public:
    Mul();
    virtual void addOperand(std::string option, double operand) override;
    virtual void execute() override;
    virtual Mul* create() override;

private:
    void registerOptions();
};

class Div : public Command {
public:
    Div();
    virtual void addOperand(std::string option, double operand) override;
    virtual void execute() override;
    virtual Div* create() override;

private:
    void registerOptions();
};

class Quit : public Command {
public:
    virtual void addOperand(std::string option, double operand) override;
    virtual void execute() override;
    virtual Quit* create() override;
};

#endif // COMMAND_CONTROLLER_COMMAND_COMMAND
