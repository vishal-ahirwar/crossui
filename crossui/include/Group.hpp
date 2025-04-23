#pragma once
#include "Widget.hpp"
#include <vector>
#include <memory>

namespace CrossUI {

class Group : public Widget {
public:
    void addChild(std::shared_ptr<Widget> widget);
    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;

private:
    std::vector<std::shared_ptr<Widget>> mChildren;
};

} // namespace CrossUI
