//Object

#ifndef OBJECT.H
#define OBJECT.H


#include <SFML/Graphics.hpp>


class Object
{
  public:
    Limit get_limits() const;

    Position get_position() const;

    sf::Image get_sprite() const;

  protected:
    //Object();

    Object(int,int,int,int,sf::Image);

    struct Size
    {
      int width{};
      int height{};
    }

    struct Position
    {
      int xpos{};
      int ypos{};
    }

    struct Limit
    {
      int left{};
      int right{};
      int upper{};
      int lower{};
    }

    sf:Sprite sprite{};
}
