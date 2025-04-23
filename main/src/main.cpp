#include <crossui/include/App.hpp>
#include <crossui/include/Button.hpp>
#include <crossui/include/Rectangle.hpp>
#include <crossui/include/Group.hpp>
#include <memory>
#include <string>
#include <iostream>

//CustomButton for Our Awesome App
auto customButton(const std::string &label, int yOffset)
{
  auto btn = std::make_shared<CrossUI::Button>(label);
  btn->setSize(220, 45);
  btn->setPosition((800 - 220) / 2, yOffset);
  btn->setCornerRadius(18);
  btn->setBackgroundColor({65, 64, 115, 255});
  btn->setBorder(1, {80, 80, 80, 255});
  return btn;
}
int main()
{
  CrossUI::App app("CrossUI | Main Menu", 800, 600);

  // Root group container
  auto root = std::make_shared<CrossUI::Group>();

  // Create Panel
  auto panel = std::make_shared<CrossUI::Rectangle>();
  int panelWidth = 300;
  int panelHeight = 300;
  panel->setPosition((800 - panelWidth) / 2, (600 - panelHeight) / 2);
  panel->setSize(panelWidth, panelHeight);
  panel->setCornerRadius(18);
  panel->setBackgroundColor({30, 30, 30, 255});
  panel->setBorder(2, {80, 80, 80, 255});
  auto loginBtn = customButton("Signin", 200);
  auto createBtn = customButton("Signup", 270);
  auto guestBtn = customButton("Guest", 340);

  // Add callbacks
  loginBtn->onClick([]{ std::cout << "Login clicked\n"; });
  createBtn->onClick([]{ std::cout << "Create clicked\n"; });
  guestBtn->onClick([]{ std::cout << "Guest clicked\n"; });

  // Add all to root group
  root->addChild(panel);
  root->addChild(loginBtn);
  root->addChild(createBtn);
  root->addChild(guestBtn);

  app.setRootWidget(root);
  return app.run();
}
