//
//Non_movable classes (.h)
//

#ifndef NON_MOVABLES_H
#define NON_MOVABLES_H
#include <SFML/Graphics.hpp>
#include "../Object.h"

//
//Platform
//
class Platform : public Object
{
  public:
    ~Platform() = default;

    Platform() = default;

    Platform(int,int,int,int,int);
};

//-----------------------------------------------

//
//Playing_field
//
class Playing_field : public Object
{
  public:
    ~Playing_field() = default;

    Playing_field() = default;

     Playing_field(int,int,int,int,int,std::vector<Object> &);//--------------------------------------------------------------------------

     Platform get_platform() const;

  protected:
    Platform platform;
};

//-----------------------------------------------

//
//Health_bar
//
class Health_bar : public Object
{
  public:
    Health_bar() = default;

    Health_bar(int,int,int,int,int);

    ~Health_bar() = default;

    void change_size(int health);
};

#endif
