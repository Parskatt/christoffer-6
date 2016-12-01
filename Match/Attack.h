#ifndef ATTACK_H
#define ATTACK_H

#include "Movable.h"
#include <SFML/Graphics.hpp>

class Attack : public Object
{
  protected:

    unique_ptr<Projectile> curr_projectile;


  public:
    Attack{int,int,int,int,int,int};

    ~Attack() = default;

    void wait();

};


class Punch : public Attack
{
  private:

  public:
    Punch{int,int,int,int,int,int};
};
