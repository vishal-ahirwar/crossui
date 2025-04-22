#pragma once
#include <SDL.h>
#include <memory>

namespace CrossUI {
class Widget {
public:
    virtual ~Widget() = default;
    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void handleEvent(const SDL_Event& event) {}
    virtual void setPosition(int x, int y) { mX = x; mY = y; }
    virtual void setSize(int w, int h) { mWidth = w; mHeight = h; }
protected:
    int mX = 0, mY = 0;
    int mWidth = 100, mHeight = 30;
};
}