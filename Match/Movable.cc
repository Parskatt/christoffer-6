//
//Movable.cc
//

#include "Movable.h"


Movable::Movable(int width ,int height ,int x, int y,std::initializer_list<std::string> il,int speed,int direction,int fallable)
    :Object{width,height,x,y,il}, speed{speed}, direction{direction}, fallable{fallable}
{}

int Movable::get_speed() const
{
  return speed;
}

int Movable::get_fallable() const
{
  return fallable;
}

/*void Movable::move()
{
  //pos.xpos = pos.xpos + direction * speed.x_speed;
}*/
