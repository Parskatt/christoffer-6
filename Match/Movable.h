//
//Movable.h
//

#ifndef MOVABLE_H
#define MOVABLE_H

#include "../Object.h"

class Movable : public Object
{
  public: //Lägger alla metoder som public tillsvidare, några borde kunna va protected

    virtual ~Movable() = default;

    virtual void move() = 0;

    int get_speed() const;

    int get_fallable() const;

  protected:

    Movable() = default;

    Movable(int,int,int,int,std::initializer_list<std::string>,int,int,int);

    int speed{};

    int direction{};

    int fallable{};

  private:

};

#endif
