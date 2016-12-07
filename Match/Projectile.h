//
//Projectile.h
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Movable.h"
#include <iostream>

class Projectile : public Movable
{
  public:

    Projectile(int,int,int,int,std::initializer_list<std::string>,int,int,int);

    ~Projectile() = default;

    void move() override;

    void render(sf::RenderWindow &);

    int get_damage() const;

  private:

    int damage;

};


class Punch_projectile : public Projectile
{
  public:

    Punch_projectile(int,int,int,int,std::initializer_list<std::string>,int,int,int);

    ~Punch_projectile() = default;

    int get_range();

  private:

    int range;

};


#endif
