//Object.cc

#include "Object.h"


//Object::Object()
//  :
//{}

Object::Object(int width,int height,int x,int y,std::initializer_list<std::string> il)
  :texture_handler{il},size{width,height},position{x,y},limit{x,x+width,y,y+height} //Object()
{
  //size.width = width;
  //size.height = height;
  //position.xpos = x;
  //position.ypos = y;
  limit.left = x;
  limit.right = x + width;
  limit.upper = y;
  limit.lower = y + height;
  //texture_index = index;

  //sprite = sf::Sprite(s);
  //sprite.setTexture(s);
  //sprite.setPosition(sf::Vector2f(x,y));
}

Object::Limit Object::get_limits() const
{
  return limit;
}

Object::Position Object::get_position() const
{
  return position;
}

/*int Object::get_texture_index()
{
  return texture_index;
}*/

Object::Size Object::get_size() const
{
  return size;
}

/*void Object::render(sf::RenderWindow & window, Texture_handler & table) //Borde hantera textures på nåt annat sätt om vi ska ha render här
{
  sf::Sprite sprite{};
  sprite.setTexture(table.get_texture(texture_index));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
}*/

void Object::update_limits()
{
  limit.left = position.xpos;
  limit.right = position.xpos + size.width;
  limit.upper = position.ypos;
  limit.lower = position.ypos + size.height;
}
