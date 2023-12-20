#include "Application.hpp"

#include <iostream>

Application& Application::getInstance() {
    static Application instance;
    return instance;
}

Document& Application::getDocument() {
    return getInstance().document_;
}

ItemRegistry& Application::getItemRegistry() {
    return getInstance().itemRegistry_;
}

ConsoleView& Application::getView() {
    return getInstance().view_;
}

bool& Application::getQuit() {
    return getInstance().quit_;
}

void Application::exec() {
    while(!quit_) {
        try {
           controller_.run(); 
        }
        catch (std::runtime_error err) {
            view_.displayMessage(err.what());
        }
    }
}

Application::Application()
: controller_(std::cin)
, view_(std::cout)
, quit_(false)
{
}