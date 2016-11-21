//Object.cc

#include "Object.h"


//Object::Object()
//  :
//{}

Object::Object(int width,int height,int x,int y,sf::Texture & s)
  :Size{width,height}, Position{x,y}
{
  sprite.setTexture(s);
  sprite.setPosition(sf::Vector2f(x,y));
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

sf::Sprite Object::get_sprite() const
{
  return sprite;
}
