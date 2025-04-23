#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <memory>
#include "Widget.hpp"
#include <SDL_ttf.h>
namespace CrossUI
{
    class App
    {
    public:
        static TTF_Font *getFont(); // Add this
        App(const char *title, int width, int height);
        ~App();
        int run();
        void setRootWidget(std::shared_ptr<Widget> root);

    private:
        SDL_Window *mWindow = nullptr;
        SDL_Renderer *mRenderer = nullptr;
        bool mRunning = true;
        std::shared_ptr<Widget> mRoot;
    };
}
