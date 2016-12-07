//Physics engine

#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

class Physics_engine
{
 private:
  bool square_collision(o1 & const,o2 & const);
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
  bool cordinate_between(int,int,int);
 protected:
 public:
  Physics_engine() = default;
  void collision(Playing_field const & , Player & , Player & ); //const;
  void gravity(Playing_field const & , Player & , Player & );
};

#endif
