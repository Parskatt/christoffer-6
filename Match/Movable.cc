//
//Movable.cc
//

#include "Movable.h"


Movable::Movable(int speed,int direction)
  :speed{speed}, direction{direction}
{
}

int get_speed() const
{
  return speed;
}

int get_fallable() const
{
  return fallable;
}
