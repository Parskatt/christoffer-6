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

  struct Position
  {
    int xpos{};
    int ypos{};
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
    Object(int width ,int height,int x,int y,int index);

    int texture_index{};
    //sf::Texture texture{};

    Size size{};

    Position position{};

    Limit limit{};

  public:

    virtual ~Object() = default;

    Limit get_limits() const;

    Position get_position() const;

    virtual void render(sf::RenderWindow &, Texture_handler &) = 0;

    void update_limits();

    //Antingen spara en texture och skapa en sprite vid utritning, eller som nu
    //spara ett index till en texture som ligger någon annanstans
    //Kan den va const och sen overrideas till inte const längre ner?
    int get_texture_index();

    //sf::Texture const & get_texture() const;
};

#endif
