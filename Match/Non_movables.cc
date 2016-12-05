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

void Platform::render(sf::RenderWindow & window, Texture_handler & table)
{
  sf::Sprite sprite{};
  sprite.setTexture(table.get_texture(texture_index));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
}
//------------------------------------------------------------

//
//Playing_field
//
Playing_field::Playing_field(int w,int h, int x, int y,int index) //sätt enum senare---------------------------------------------------------------------
  :Object{w,h,x,y,index}, platform{1280,200,0,500,0}
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

void Playing_field::render(sf::RenderWindow & window, Texture_handler & table)
{
  sf::Sprite sprite{};
  sprite.setTexture(table.get_texture(texture_index));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);

  platform.render(window,table);
}
//-----------------------------------------------------------

//
//Health_bar
//
Health_bar::Health_bar(int w,int h,int x,int y,int index,int health,int direction)
  :Object{w,h,x,y,index},size{health},direction{direction}
{}

void Health_bar::render(sf::RenderWindow & window, Texture_handler & table)
{
  sf::RectangleShape bar;
  bar.setSize(sf::Vector2f(direction*size,40));
  bar.setFillColor(sf::Color::Red);
  bar.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(bar);
}

void Health_bar::size_(int health)
{
  size = health;
  //sf::RectangleShape black;
  //bar.setSize(100 - health, 20);
  //bar.setFillColor(sf::Color::Black);
  //bar.setPosition(sf::Vector2f(health, 20));

  //sprite.scale((health/100), 1);

}
