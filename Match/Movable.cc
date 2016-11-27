//
//Movable.cc
//

#include "Movable.h"


Movable::Movable(int width ,int height ,int x, int y,int index,int speed,int direction,int fallable)
    :Object{width,height,x,y,index}, speed{speed}, direction{direction}, fallable{fallable}
{

}

int Movable::get_speed() const
{
  return speed;
}

int Movable::get_fallable() const
{
  return fallable;
}

void Movable::move()
{
  //pos.xpos = pos.xpos + direction * speed.x_speed;
}
