#include <crossui/include/App.hpp>
#include <crossui/include/Button.hpp>
#include <crossui/include/Rectangle.hpp>
#include <crossui/include/Group.hpp> // New!

#include <memory>
#include <format>
#include <print>
#include <chrono>
#include <thread>
#include <iostream>

void currentDateTime()
{
  using namespace std::chrono;
  std::print("Current Date Time is : {}\n", zoned_time{current_zone(), system_clock::now()});
}

int main()
{
  CrossUI::App app("CrossUI Hello", 800, 600);

  auto group = std::make_shared<CrossUI::Group>();

  auto btn = std::make_shared<CrossUI::Button>("Print");
  btn->setPosition(350, 250);
  btn->setSize(190, 45);
  btn->setBorder(1, {255, 255, 255, 255});
  btn->onClick(&currentDateTime);

  auto panel = std::make_shared<CrossUI::Rectangle>();
  panel->setPosition(320, 200);
  panel->setSize(600, 400);
  panel->setCornerRadius(12);
  panel->setBackgroundColor({40, 40, 40, 255});
  panel->setBorder(2, {0, 255, 255, 255});

  // Add both to group
  group->addChild(panel);
  group->addChild(btn);

  app.setRootWidget(group);

  return app.run();
}
