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

bool& Application::getQuit() {
    return getInstance().quit_;
}

void Application::exec() {
    while(!quit_) {
        try {
           controller_.run(); // TK: This way you can't make your app UI based, pass input stream to the run as an argument istead of constructor 
        }
        catch (std::runtime_error err) {
            std::cout << err.what() << std::endl;
        }
    }
}

Application::Application()
: controller_(std::cin)
, quit_(false)
{
}
