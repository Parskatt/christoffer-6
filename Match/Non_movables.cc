/*
*Non_movable classes (.cc)
*/

#include "Non_movables.h"

Platform::Platform(int w,int h,int x,int y,sf::Image i)
  :Object(x,y,i)
{}

Playing_field::Playing_field(int w,int h,int x,int y,sf::Image i)
  :Object(x,y,i)
{
  platform{w,200,x,600,'some image'};
}
