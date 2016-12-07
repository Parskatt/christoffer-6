/*
*Non_movable classes (.cc)
*/

#include "Non_movables.h"
//
//Platform
//
Platform::Platform(int w,int h,int x,int y,std::initializer_list<std::string> il)
  :Object{w,h,x,y,il}
{}

void Platform::render(sf::RenderWindow & window)
{
  sf::Sprite sprite{};
  sprite.setTexture(texture_handler.get_texture(0));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
}
//------------------------------------------------------------

//
//Playing_field
//
Playing_field::Playing_field(int w,int h, int x, int y,std::initializer_list<std::string> il) //sätt enum senare---------------------------------------------------------------------
  :Object{w,h,x,y,il}, platform{1280,200,0,500,{"Bilder/tom.png"}} //Skickar in il till platform även fast den är osynlig för enkelhetens skull
{
    //nonmovable_objects.push_back(std::make_unique<Platform>(platform));//(1280,200,0,500,1));
    //platform = *dynamic_cast<Platform*>(nonmovable_objects.back().get());

      //platform = Platform{1280,200,0,500,1};
      //nonmovable_objects.push_back(&platform);//------------------------------------------------------------------------------------------------
}

Platform Playing_field::get_platform() const
{
  return platform;
}

void Playing_field::render(sf::RenderWindow & window)
{
  sf::Sprite sprite{};
  sprite.setTexture(texture_handler.get_texture(0));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);

  platform.render(window);
}
//-----------------------------------------------------------

//
//Health_bar
//
Health_bar::Health_bar(int w,int h,int x,int y,std::initializer_list<std::string> il,int health,int direction)
  :Object{w,h,x,y,il},size{health},direction{direction}
{}

void Health_bar::render(sf::RenderWindow & window)
{
  sf::RectangleShape bar;
  bar.setSize(sf::Vector2f(direction*size,40));
  bar.setFillColor(sf::Color::Red);
  bar.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(bar);
}

void Health_bar::set_size(int health)
{
  size = health;
  //sf::RectangleShape black;
  //bar.setSize(100 - health, 20);
  //bar.setFillColor(sf::Color::Black);
  //bar.setPosition(sf::Vector2f(health, 20));

  //sprite.scale((health/100), 1);

}
