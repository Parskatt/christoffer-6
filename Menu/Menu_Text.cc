#include "Menu_Text.h"


Menu_Text::Menu_Text(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Object{width,height,x,y,il}
{}







void Menu_Text::render(sf::RenderWindow & window)
{
  sf::Sprite sprite{};
  sprite.setTexture(texture_handler.get_texture(0));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
}
