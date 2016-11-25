//
//Movable.h
//

#ifndef MOVABLES_H
#define MOVABLES_H

#include "../Object.h"

class Movable : public Object
{
  public: //Lägger alla metoder som public tillsvidare, några borde kunna va protected

    ~Movable() = default;

    Movable() = default;

    Movable(int width ,int height ,int x, int y,int index,int speed,int direction);

    virtual void move() = 0;

    int get_speed(); const

    int get_fallable() const;

  protected:

    int speed{};

    int direction{};

    int fallable{};

  private:

};

#endif
