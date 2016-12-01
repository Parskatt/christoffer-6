#ifndef ATTACK_H
#define ATTACK_H

#include "Movable.h"
#include <SFML/Graphics.hpp>

class Attack : public Object
{
  protected:

    unique_ptr<Projectile> curr_projectile;


  public:
    Attack{int width,int height,int x,int y,int index};

    ~Attack() = default;

};


class Punch : public Attack
{
  private:

  public:
    Punch{int width ,int height,int x,int y,int index};

    int get_texture_index() override;
};
