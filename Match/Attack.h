#ifndef ATTACK_H
#define ATTACK_H

#include "Movable.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Attack : public Object
{
  protected:

  //  Projectile curr_projectile;
  int direction;
  int done_counter{};
  int render_counter{};
  public:

    ~Attack() = default;

    Attack() = default;

    Attack(int,int,int,int,std::initializer_list<std::string>,int);



    //void wait();

    void render(sf::RenderWindow &) override;
    bool done();
    void set_xpos(int);
    void set_ypos(int);

};


class Punch : public Attack
{
  private:

  public:
    //~Punch() = default;

    //Punch() = default;

    Punch(int,int,int,int,std::initializer_list<std::string>,int,std::vector<Projectile> &);
};

#endif
