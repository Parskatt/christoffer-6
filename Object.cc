//Object.cc

#include "Object.h"

//Object::Object()
//  :
//{}

Object::Object(int width,int height,int x,int y,int index)
  :Object()
{
  size.width = width;
  size.height = height;
  pos.xpos = x;
  pos.ypos = y;
  lim.left = x;
  lim.right = x + width;
  lim.upper = y;
  lim.lower = y + height;
  texture_index = index;

  //sprite = sf::Sprite(s);
  //sprite.setTexture(s);
  //sprite.setPosition(sf::Vector2f(x,y));
}

Object::Limit Object::get_limits() const
{
  return lim;
}

Object::Position Object::get_position() const
{
  return pos;
}

int Object::get_texture_index()
{
  return texture_index;
}

void Object::uppdate_limit()
{
  lim.left = x;
  lim.right = x + width;
  lim.upper = y;
  lim.lower = y + height;
}
