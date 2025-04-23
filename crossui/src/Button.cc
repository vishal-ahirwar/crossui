
// File: src/Button.cpp
#include "crossui/include/Button.hpp"
#include <SDL_ttf.h>
#include <SDL.h>
#include "crossui/include/App.hpp"
#include "crossui/include/GraphicsUtils.hpp"
namespace CrossUI
{
    Button::Button(const std::string &text) : mText(text) {}

    void Button::onClick(std::function<void()> cb)
    {
        mOnClick = cb;
    }

    void Button::handleEvent(const SDL_Event &event)
    {
        if (event.type == SDL_MOUSEMOTION)
        {
            int mx = event.motion.x;
            int my = event.motion.y;
            mHovered = mx >= mX && mx <= mX + mWidth && my >= mY && my <= mY + mHeight;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
        {
            int mx = event.button.x;
            int my = event.button.y;
            if (mx >= mX && mx <= mX + mWidth && my >= mY && my <= mY + mHeight)
            {
                if (mOnClick)
                    mOnClick();
            }
        }
    }

    void Button::draw(SDL_Renderer *renderer)
    {
        SDL_Rect rect = {mX, mY, mWidth, mHeight};
        if (mHovered)
            SDL_SetRenderDrawColor(renderer, 70, 70, 200, 255); // darker blue
        else
            SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255); // normal
                                                                  // Border
        if (mBorderThickness > 0)
        {
            SDL_SetRenderDrawColor(renderer, mBorderColor.r, mBorderColor.g, mBorderColor.b, mBorderColor.a);
            drawRoundedRect(renderer, rect, mCornerRadius);
        }

        // Inner background
        SDL_Color fillColor = mHovered ? mHoverColor : mBgColor;
        SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);

        SDL_Rect inner = {
            mX + mBorderThickness,
            mY + mBorderThickness,
            mWidth - 2 * mBorderThickness,
            mHeight - 2 * mBorderThickness};

        drawRoundedRect(renderer, inner, std::max(0, mCornerRadius - mBorderThickness));

        if (!mText.empty())
        {
            SDL_Color color = {255, 255, 255};
            SDL_Surface *surface = TTF_RenderText_Blended(CrossUI::App::getFont(), mText.c_str(), color);
            if (surface)
            {
                SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
                int tw = surface->w, th = surface->h;
                SDL_Rect dst = {mX + (mWidth - tw) / 2, mY + (mHeight - th) / 2, tw, th};
                SDL_RenderCopy(renderer, texture, nullptr, &dst);
                SDL_FreeSurface(surface);
                SDL_DestroyTexture(texture);
            }
        }
    }
}
