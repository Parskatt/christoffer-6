//
//Non_movable classes (.h)
//

#include "Object.h"

//
//Platform
//
class Platform : public Object
{
  public:
    ~Platform() = default;

    Platform(int,int,int,int,sf::Texture);
}

//-----------------------------------------------

//
//Playing_field
//
class Playing_field : public Object
{
  public:
    ~Playing_field() = default;

     Playing_field(int,int,int,int,sf::Texture);

     Platform get_platform() const;

  protected:
    Platform platform{};
}

//-----------------------------------------------

//
//Health_bar
//
class Health_bar : public Object
{
  public:
    Health_bar(int,int,int,int,sf::Texture);

    ~Health_bar() = default;

    void change_size(int health);
}
