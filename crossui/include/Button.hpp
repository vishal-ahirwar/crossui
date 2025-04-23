#pragma once
#include "Widget.hpp"
#include <string>
#include <functional>

namespace CrossUI
{
    class Button : public Widget
    {
    public:
        Button(const std::string &text);
        void draw(SDL_Renderer *renderer) override;
        void handleEvent(const SDL_Event &event) override;
        void onClick(std::function<void()> cb);

    private:
        std::string mText;
        std::function<void()> mOnClick;
        bool mHovered = false;

    private:
        int mCornerRadius = 8;
        SDL_Color mBgColor = {100, 100, 255, 255};
        SDL_Color mHoverColor = {70, 70, 200, 255};
        SDL_Color mTextColor = {255, 255, 255, 255};

    public:
        void setCornerRadius(int r) { mCornerRadius = r; }
        void setBackgroundColor(SDL_Color color) { mBgColor = color; }
        void setHoverColor(SDL_Color color) { mHoverColor = color; }
        void setTextColor(SDL_Color color) { mTextColor = color; }

    private:
        int mBorderThickness = 0;
        SDL_Color mBorderColor = {0, 0, 0, 255}; // Default: black

    public:
        void setBorder(int thickness, SDL_Color color)
        {
            mBorderThickness = thickness;
            mBorderColor = color;
        }
    };
}
