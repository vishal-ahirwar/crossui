#define SDL_MAIN_HANDLED
#include <crossui/include/App.hpp>
#include <crossui/include/Button.hpp>
#include <memory>

int main()
{
  CrossUI::App app("CrossUI Hello", 800, 600);
  auto btn = std::make_shared<CrossUI::Button>("Click Me!");
  btn->setPosition(350, 250);
  btn->onClick([](){ printf("Button clicked!\n"); });
  app.setRootWidget(btn);
  return app.run();
}
