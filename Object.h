//Object

#ifndef OBJECT_H
#define OBJECT_H


#include <SFML/Graphics.hpp>
#include "Texture_handler.h"


class Object
{
private:
  struct Size
  {
    int width{};
    int height{};
  };

  struct Limit
  {
    int left{};
    int right{};
    int upper{};
    int lower{};
  };

  protected:
    Object() = default;
    Object(int width ,int height,int x,int y,std::initializer_list<std::string> = {"Bilder/tom.png"});

    struct Position
    {
      int xpos{};
      int ypos{};
    };

    Texture_handler texture_handler{};

    Size size{};

    Position position{};

    Limit limit{};

  public:

    virtual ~Object() = default;

    Limit get_limits() const;

    Position get_position() const;

    Size get_size() const;

    virtual void render(sf::RenderWindow &) = 0;

    void update_limits();
};

#endif
