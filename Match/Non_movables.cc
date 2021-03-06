/*
*Non_movable classes (.cc)
*/
#include <iostream>
#include "Non_movables.h"
//
//Platform
//
Platform::Platform(int w,int h,int x,int y)
  :Object{w,h,x,y}
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
Playing_field::Playing_field(int w,int h, int x, int y,int playing_field)
  :Object{w,h,x,y}, platform{1280,200,0,700}
{
  switch(playing_field)
  {
    case 1:
    {
      texture_handler = Texture_handler{{"Bilder/boxing_ring.png"}};
      break;
    }
    case 2:
    {
      texture_handler = Texture_handler{{"Bilder/background1.png"}};
      break;
    }
  }
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
Health_bar::Health_bar(int health,int direction)
  :bar_size{health},direction{direction}
{
  switch(direction)
  {
    case 1:
    {
      size.width = 200;
      size.height = 50;
      position.xpos = 50;
      position.ypos = 50;
      break;
    }
    case -1:
    {
      size.width = 200;
      size.height = 50;
      position.xpos = 1230;
      position.ypos = 50;
      break;
    }
  }
}

void Health_bar::render(sf::RenderWindow & window)
{
  sf::RectangleShape bar;
  bar.setSize(sf::Vector2f(3*direction*bar_size,40));
  bar.setOutlineColor(sf::Color::Black);
  bar.setOutlineThickness(5);
  bar.setFillColor(sf::Color::Red);
  bar.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(bar);
}

void Health_bar::set_size(int health)
{
  bar_size = health;
}
