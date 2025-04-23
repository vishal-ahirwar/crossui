#include "crossui/include/Group.hpp"

namespace CrossUI {

void Group::addChild(std::shared_ptr<Widget> widget) {
    mChildren.push_back(widget);
}

void Group::draw(SDL_Renderer* renderer) {
    for (auto& child : mChildren) {
        child->draw(renderer);
    }
}

void Group::handleEvent(const SDL_Event& event) {
    for (auto& child : mChildren) {
        child->handleEvent(event);
    }
}

} // namespace CrossUI
