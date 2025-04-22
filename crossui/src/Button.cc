
// File: src/Button.cpp
#include "crossui/include/Button.hpp"
#include <SDL_ttf.h>
#include <SDL.h>
#include <iostream>

namespace CrossUI {
Button::Button(const std::string& text) : mText(text) {}

void Button::onClick(std::function<void()> cb) {
    mOnClick = cb;
}

void Button::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int mx = event.button.x, my = event.button.y;
        if (mx >= mX && mx <= mX + mWidth && my >= mY && my <= mY + mHeight && mOnClick) {
            mOnClick();
        }
    }
}

void Button::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { mX, mY, mWidth, mHeight };
    SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    // Text rendering omitted for now
}
}

