//
//Game.cc
//

#include "Match/Match.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  /*
  Menu menu();
  menu.run();
  char1 = menu.char1;
  char2 = menu.char2;
  background = {menu.background};
  */
  Match match{1,2,1};
  match.run();

  return 0;
}
