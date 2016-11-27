//
//Movable.h
//

#ifndef MOVABLE_H
#define MOVABLE_H

#include "../Object.h"

class Movable : public Object
{
  public: //Lägger alla metoder som public tillsvidare, några borde kunna va protected

  ~Movable() = default;

    void move();

    int get_speed() const;

    int get_fallable() const;

  protected:

    Movable() = default;

    Movable(int,int,int,int,int,int,int,int);

    int speed{};

    int direction{};

    int fallable{};

  private:

};

#endif
