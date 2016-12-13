#ifndef MENU_TEXT_H
#define MENU_TEXT_H

#include "../Object.h"
#include <string>



class Menu_Text : public Object
{
public:
  Menu_Text(int width ,int height,int x,int y,std::initializer_list<std::string> il);
  Menu_Text() = default;

  void render(sf::RenderWindow &) override;
};
#endif
