#pragma once
#include "Widget.hpp"
#include <functional>
#include <SDL.h>

namespace CrossUI {

class Rectangle : public Widget {
public:
    Rectangle();

    // Visual customization
    void setCornerRadius(int r);
    void setBackgroundColor(SDL_Color color);
    void setBorder(int thickness, SDL_Color color);

    // Event callbacks
    void setOnHover(std::function<void()> callback);
    void setOnClick(std::function<void()> callback);
    void setOnKeyDown(std::function<void(SDL_Keycode)> callback);

    void handleEvent(const SDL_Event& event) override;
    void draw(SDL_Renderer* renderer) override;

private:
    int mCornerRadius = 0;
    SDL_Color mBgColor = {200, 200, 200, 255};
    SDL_Color mBorderColor = {0, 0, 0, 255};
    int mBorderThickness = 0;

    bool mIsHovered = false;

    std::function<void()> mOnHover;
    std::function<void()> mOnClick;
    std::function<void(SDL_Keycode)> mOnKeyDown;
};

} // namespace CrossUI
