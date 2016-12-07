//
//Non_movable classes (.h)
//

#ifndef NON_MOVABLES_H
#define NON_MOVABLES_H
#include <SFML/Graphics.hpp>
#include "../Object.h"
#include <memory>

//
//Platform
//
class Platform : public Object
{
  public:
    ~Platform() = default;

    Platform() = default;

    Platform(int,int,int,int,std::initializer_list<std::string>);

    void render(sf::RenderWindow &) override;
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

     Playing_field(int,int,int,int,std::initializer_list<std::string>);//--------------------------------------------------------------------------

     Platform get_platform() const;

     void render(sf::RenderWindow &) override;

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

    Health_bar(int,int,int,int,std::initializer_list<std::string>,int,int);

    ~Health_bar() = default;

    void render(sf::RenderWindow &)  override;

    void set_size(int health);

  private:
    int size{};

    int direction{};
};

#endif
