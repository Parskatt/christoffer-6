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

    ~Attack() = default;

    Attack() = default;
    
    Attack(int,int,int,int,int,int);



    //void wait();

    void render(sf::RenderWindow & window, Texture_handler & table) override;

};


class Punch : public Attack
{
  private:

  public:
    ~Punch() = default;

    Punch() = default;

    Punch(int,int,int,int,int,int);
};

#endif
