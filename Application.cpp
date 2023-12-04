#include "Application.hpp"

#include <iostream>

Application& Application::getInstance() {
    static Application instance;
    return instance;
}

Document& Application::getDocument() {
    return getInstance()._document;
}

ItemRegistry& Application::getItemRegistry() {
    return getInstance()._itemRegistry;
}

bool& Application::getQuit() {
    return getInstance()._quit;
}

void Application::exec() {
    while(!_quit) {
        try {
           _controller.run(); 
        }
        catch (std::runtime_error err) {
            std::cout << err.what() << std::endl;
        }
    }
}

Application::Application()
: _controller(std::cin)
, _quit(false)
{
}