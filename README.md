# CrossUI

A lightweight, cross-platform UI framework built using **SDL2** and **C++**.  
CrossUI provides a simple way to create interactive GUI applications that run on Windows, Linux, macOS, and even mobile platforms.

---

## ✨ Features

- 🔌 Built on top of [SDL2](https://www.libsdl.org/)
- 🧱 Basic widget system (Button, Layouts, etc.)
- 🎨 Customizable UI with plans for theming
- 🧭 Easy event handling
- 🧰 CMake-based project structure

---

## 📸 Preview
```
#include <memory>
#include <string>
#include <crossui/include/App.hpp>
#include <crossui/include/Button.hpp>
#include <crossui/include/Rectangle.hpp>
#include <crossui/include/Group.hpp>

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

```
![image](https://github.com/user-attachments/assets/f084385b-0d5d-4e0f-b893-a9c8dff72324)

---

## 🔧 Getting Started

### 🔨 Prerequisites

Make sure you have the following installed:

- SDL2
- SDL2_ttf
- CMake 3.16+
- A C++17-compatible compiler

### 🛠️ Build Instructions

```bash
git clone https://github.com/vishal-ahirwar/crossui.git
cd crossui
aura build main
