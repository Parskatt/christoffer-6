/*
*Non_movable classes (.cc)
*/

#include "Non_movables.h"

//
//Platform
//
Platform::Platform(int w,int h,int x,int y,sf::Texture & t)
  :Object(w,h,x,y,t)
{}
//------------------------------------------------------------

//
//Playing_field
//
Playing_field::Playing_field(int i) //sätt enum senare
{
  switch(i)
  {
    case 1:
      sf::Texture background;
      sf::Texture platform_texture;
      background.loadFromFile("background.png");
      platform_texture.loadFromFile("platform.png");

      Object(1280,720,0,0,background);
      platform{1280,200,0,500,platform_texture};
  }
}

Platform Playing_field::get_platform() const
{
  return platform;
}
//-----------------------------------------------------------

//
//Health_bar
//
Health_bar::Health_bar(int w,int h,int x,int y,sf::Texture & t)
  :Object(w,h,x,y,t)
{}

void Health_bar::change_size(int health)
{
/*  sf::RectangleShape bar;
  bar.setSize(health, 20);
  bar.setFillColor(sf::Color::Red);

  sf::RectangleShape black;
  bar.setSize(100 - health, 20);
  bar.setFillColor(sf::Color::Black);
  bar.setPosition(sf::Vector2f(health, 20));*/

  sprite.scale((health/100), 1)

}
