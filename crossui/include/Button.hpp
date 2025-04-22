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
    };
}
