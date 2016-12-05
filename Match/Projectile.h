//
//Projectile.h
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Movable.h"

class Projectile : public Movable
{
  public:

    Projectile(int,int,int,int,int,int,int,int);

    ~Projectile() = default;

    void move() override;

  private:

    int damage;

};


class Punch_projectile : public Projectile
{
  public:

    Punch_projectile(int,int,int,int,int);

    ~Punch_projectile() = default;

    int get_range();

  private:

    int range;

};


#endif
