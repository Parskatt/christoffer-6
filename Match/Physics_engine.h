//Physics engine

#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include "Player.h"
#include "Non_movables.h"
#include "../Object.h"


class Physics_engine
{
 private:

  int square_super_collision(Object const & o1, Object const & o2);
  bool square_collision(Object const & ,Object const & );
  bool square_below_collision(Object const & ,Object const & );
  bool square_above_collision(Object const & ,Object const & );
  bool square_y_collision(Object const & ,Object const & );
  bool square_x_collision(Object const & ,Object const & );
  bool square_y_collide(Object const & ,Object const & );
  bool cordinate_between(int ,int ,int );
  bool object_outside_x(Object const & );
  bool object_above (Object const & );
  bool object_below (Object const & );
  bool object_outside (Object const & );

 protected:

 public:

  ~Physics_engine() = default;
  Physics_engine() = default;

  void collision(Playing_field const & , Player & , Player & );
  void gravity(Player & , Player & );


};

#endif
