//
//Projectile.h
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../Object.h"
#include <iostream>

class Projectile : public Object
{
  public:

    Projectile(int,int,int,int,std::initializer_list<std::string>,int,int,int,int);

    ~Projectile() = default;

    void move();

    void render(sf::RenderWindow &);

    int get_range();

    int get_damage() const;

    bool done();

  private:

    int damage;
    int done_counter;
    int range;
    int speed{};
    int direction{};
};


class Punch_projectile : public Projectile
{
  public:

    Punch_projectile(int,int,int,int,int,int,int);

    ~Punch_projectile() = default;
};


#endif
