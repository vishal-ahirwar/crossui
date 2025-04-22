#pragma once
#include <SDL.h>
#include <memory>
#include "Widget.hpp"

namespace CrossUI {
class App {
public:
    App(const char* title, int width, int height);
    ~App();
    int run();
    void setRootWidget(std::shared_ptr<Widget> root);

private:
    SDL_Window* mWindow = nullptr;
    SDL_Renderer* mRenderer = nullptr;
    bool mRunning = true;
    std::shared_ptr<Widget> mRoot;
};
}
