/*
*Non_movable classes (.cc)
*/

#include "Non_movables.h"
//
//Platform
//
Platform::Platform(int w,int h,int x,int y,int index)
  :Object{w,h,x,y,index}
{}
//------------------------------------------------------------

//
//Playing_field
//
Playing_field::Playing_field(int w,int h, int x, int y,int index, std::vector<Object*> & nonmovable_objects) //sätt enum senare---------------------------------------------------------------------
  :Object{w,h,x,y,index}
{
      platform = Platform{1280,200,0,500,1};
      nonmovable_objects.push_back(&platform);//------------------------------------------------------------------------------------------------
}

Platform Playing_field::get_platform() const
{
  return platform;
}
//-----------------------------------------------------------

//
//Health_bar
//
Health_bar::Health_bar(int w,int h,int x,int y,int index)
  :Object{w,h,x,y,index}
{}

void Health_bar::render(sf::RenderWindow & window, Texture_handler & table)
{
  sf::RectangleShape bar;
  bar.setSize(sf::Vector2f(200, 40));
  bar.setFillColor(sf::Color::Red);
  bar.setPosition(sf::Vector2f(50,50));
  window.draw(bar);
}

void Health_bar::change_size(int health)
{


  //sf::RectangleShape black;
  //bar.setSize(100 - health, 20);
  //bar.setFillColor(sf::Color::Black);
  //bar.setPosition(sf::Vector2f(health, 20));

  //sprite.scale((health/100), 1);

}
