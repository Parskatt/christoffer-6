//Object.cc

#include "Object.h"

Object::Object(int x,int y,sf::Sprite s)
  :Size{s.getGlobalBounds().width,s.getGlobalBounds().height},
  Position{x,y}, bitmap{i}
{
  Limit{x,x + Size.width,y,y+Size.height};
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
