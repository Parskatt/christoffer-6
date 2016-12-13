//Object.cc

#include "Object.h"

Object::Object(int width,int height,int x,int y,std::initializer_list<std::string> il)
  :texture_handler{il},size{width,height},position{x,y},limit{x,x+width,y,y+height} //Object()
{
  limit.left = x;
  limit.right = x + width;
  limit.upper = y;
  limit.lower = y + height;
}

Object::Limit Object::get_limits() const
{
  return limit;
}

Object::Position Object::get_position() const
{
  return position;
}

Object::Size Object::get_size() const
{
  return size;
}

void Object::update_limits()
{
  limit.left = position.xpos;
  limit.right = position.xpos + size.width;
  limit.upper = position.ypos;
  limit.lower = position.ypos + size.height;
}
