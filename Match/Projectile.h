//
//Projectile.h
//

#ifndef PROJECTILE_H
#define PROJECTILE_H


class Projectile : public Movable
{
  public:

    Projectile(int,int,int,int,int,int,int,int);

    ~Projectile = default;

    void move() override;

  private:

    int damage;

    Character source;

};


class Punch_projectile : Projectile
{
  public:

    Punch_projectile();

    ~Punch_projectile();

    int get_range();

  private:

    int range;

};


#endif