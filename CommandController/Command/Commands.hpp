#ifndef COMMAND_CONTROLLER_COMMAND_COMMAND
#define COMMAND_CONTROLLER_COMMAND_COMMAND

#include "Command.hpp"

#include "../ItemRegistry/ItemRegistry.hpp"

class Add : public Command {
public:
    Add();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute(Document& doc) override;
    virtual Add* create() override;

private:
    void registerOptions();

private:
    ItemRegistry itemRegistry_;
};

class Change : public Command {
public:
    Change();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute(Document& doc) override;
    virtual Change* create() override;

private:
    void registerOptions();
};

class Remove : public Command {
public:
    Remove();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute(Document& doc) override;
    virtual Remove* create() override;

private:
    void registerOptions();
};

class Display : public Command {
public:
    Display();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute(Document& doc) override;
    virtual Display* create() override;

private:
    void registerOptions();
};

class Quit : public Command {
public:
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute(Document&) override;
    virtual Quit* create() override;
};

#endif // COMMAND_CONTROLLER_COMMAND_COMMAND
