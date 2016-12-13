#include "Menu/Menu.h"
#include <SFML/Graphics.hpp>

int main()
{
  bool running{true};
  while(running)
  {
  Menu menu{};
  menu.menu_loop(running);
  }
  return 0;
}
