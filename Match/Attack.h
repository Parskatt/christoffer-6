#ifndef ATTACK_H
#define ATTACK_H

#include "Movable.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>

class Attack : public Object
{
  protected:

  //  Projectile curr_projectile;


  public:
    Attack(int,int,int,int,int,int);

    ~Attack() = default;

    //void wait();

    void render(sf::RenderWindow & window, Texture_handler & table) override;

};


class Punch : public Attack
{
  private:

  public:
    Punch(int,int,int,int,int,int);
};

#endif
