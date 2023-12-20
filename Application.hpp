#ifndef OOP_APPLICATION_HPP
#define OOP_APPLICATION_HPP

#include "CommandController/Controller/CommandController.hpp"
#include "Document/Document/Document.hpp"
#include "CommandController/ItemRegistry/ItemRegistry.hpp"
#include "View/ConsoleView.hpp"

class Application {
public:
    static Application& getInstance();
    static Document& getDocument();
    static ItemRegistry& getItemRegistry();
    static ConsoleView& getView();
    static bool& getQuit();
    void exec();

public:
    Application(const Application&) =delete;
    Application& operator=(const Application&) =delete;

private:
    Application();
    ~Application() =default;

private:
    CommandController controller_;
    Document document_;
    ItemRegistry itemRegistry_;
    ConsoleView view_;
    bool quit_;
};

#endif // OOP_APPLICATION_HPP