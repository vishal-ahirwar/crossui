// File: src/App.cpp
#include "crossui/include/App.hpp"
#include <SDL_ttf.h>

namespace CrossUI
{
    static TTF_Font *gFont = nullptr;

    App::App(const char *title, int width, int height)
    {
        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();

        gFont = TTF_OpenFont("res/FiraCode-Retina.ttf", 20); // Load a font

        mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    }

    TTF_Font *App::getFont()
    {
        return gFont;
    }

    App::~App()
    {
        TTF_CloseFont(gFont);
        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);
        TTF_Quit();
        SDL_Quit();
    }

    void App::setRootWidget(std::shared_ptr<Widget> root)
    {
        mRoot = root;
    }

    int App::run()
    {
        SDL_Event event;
        while (mRunning)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    mRunning = false;
                if (mRoot)
                    mRoot->handleEvent(event);
            }
            SDL_SetRenderDrawColor(mRenderer, 30, 30, 30, 255);
            SDL_RenderClear(mRenderer);
            if (mRoot)
                mRoot->draw(mRenderer);
            SDL_RenderPresent(mRenderer);
        }
        return 0;
    }
}
