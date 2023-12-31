#ifndef OOP_COMMAND_CONTROLLER_COMMAND_COMMANDS_HPP
#define OOP_COMMAND_CONTROLLER_COMMAND_COMMANDS_HPP

#include "Command.hpp"

#include "../ItemRegistry/ItemRegistry.hpp"

class AddItem : public Command {
public:
    AddItem();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute() override;
    virtual AddItem* create() override;

private:
    void registerOptions();

private:
    ItemRegistry itemRegistry_;
};

class AddSlide : public Command {
public:
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute() override;
    virtual AddSlide* create() override;
};

class Change : public Command {
public:
    Change();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute() override;
    virtual Change* create() override;

private:
    void registerOptions();
};

class RemoveItem : public Command {
public:
    RemoveItem();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute() override;
    virtual RemoveItem* create() override;

private:
    void registerOptions();
};

class RemoveSlide : public Command {
public:
    RemoveSlide();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute() override;
    virtual RemoveSlide* create() override;

private:
    void registerOptions();
};

class Display : public Command {
public:
    Display();
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute() override;
    virtual Display* create() override;

private:
    void registerOptions();
};

class Quit : public Command {
public:
    virtual void addOperand(std::string option, OperandType operand) override;
    virtual void execute() override;
    virtual Quit* create() override;
};

#endif // OOP_COMMAND_CONTROLLER_COMMAND_COMMANDS_HPP
