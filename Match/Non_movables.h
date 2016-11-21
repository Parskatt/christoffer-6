/*
*Non_movable classes (.h)
*/

#include "Object.h"

class Platform : public Object
{
  public:
    ~Platform()=default;

    Platform(int,int,int,int,sf::Image);
}

class Playing_field : public Object
{
  public:
    ~Playing_field()=default;

     Playing_field(int,int,int,int,sf::Image);

  protected:
    Platform platform{};
}
