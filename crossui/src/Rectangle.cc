#include "crossui/include/Rectangle.hpp"
#include <crossui/include/GraphicsUtils.hpp>
namespace CrossUI
{

    Rectangle::Rectangle() {}

    void Rectangle::setCornerRadius(int r) { mCornerRadius = r; }
    void Rectangle::setBackgroundColor(SDL_Color color) { mBgColor = color; }
    void Rectangle::setBorder(int thickness, SDL_Color color)
    {
        mBorderThickness = thickness;
        mBorderColor = color;
    }
    void Rectangle::setOnHover(std::function<void()> callback) { mOnHover = callback; }
    void Rectangle::setOnClick(std::function<void()> callback) { mOnClick = callback; }
    void Rectangle::setOnKeyDown(std::function<void(SDL_Keycode)> callback) { mOnKeyDown = callback; }

    void Rectangle::handleEvent(const SDL_Event &event)
    {
        if (event.type == SDL_MOUSEMOTION)
        {
            int mx = event.motion.x;
            int my = event.motion.y;
            bool hovering = mx >= mX && mx <= mX + mWidth && my >= mY && my <= mY + mHeight;
            if (hovering && !mIsHovered && mOnHover)
                mOnHover();
            mIsHovered = hovering;
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

        if (event.type == SDL_KEYDOWN)
        {
            if (mOnKeyDown)
                mOnKeyDown(event.key.keysym.sym);
        }
    }

    void Rectangle::draw(SDL_Renderer *renderer)
    {
        SDL_Rect outer = {mX, mY, mWidth, mHeight};

        if (mBorderThickness > 0)
        {
            SDL_SetRenderDrawColor(renderer, mBorderColor.r, mBorderColor.g, mBorderColor.b, mBorderColor.a);
            drawRoundedRect(renderer, outer, mCornerRadius);
        }

        SDL_Rect inner = {
            mX + mBorderThickness,
            mY + mBorderThickness,
            mWidth - 2 * mBorderThickness,
            mHeight - 2 * mBorderThickness};

        SDL_SetRenderDrawColor(renderer, mBgColor.r, mBgColor.g, mBgColor.b, mBgColor.a);
        drawRoundedRect(renderer, inner, std::max(0, mCornerRadius - mBorderThickness));
    }

} // namespace CrossUI
