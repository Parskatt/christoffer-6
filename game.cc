//
//Game.cc
//

#include "Match/Match.h"
#include "Menu/Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  bool running{true};
  while(running)
  {
  Menu menu{};
  menu.menu_loop(running);
  int char1 = menu.get_char1();
  int char2 = menu.get_char2();
  int background = menu.get_playingfield();
  Match match{char1,char2,background};
  match.run(running);
  }
  return 0;
}
