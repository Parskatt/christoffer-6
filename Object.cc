//Object.cc

#include "Object.h"

Object::Object(int width,int height,int x,int y,sf::Sprite s)
  :Size{width,height}, Position{x,y}, bitmap{i}
{
  Limit{x,x+width,y,y+height};
}

Object::Limit Object::get_limits() const
{
  return Limit;
}

Object::Position Object::get_position() const
{
  return Position;
}

sf::Image Object::get_bitmap() const
{
  return bitmap;
}
