//Physics engine

#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

class Physics_engine
{
 private:
  bool square_collision(o1 & const,o2 & const) const;
  bool cordinate_between(x, i1, i2);
 protected:
 public:
  vector collision(movable_objects &, nonmovable_objects &) const;

};

#endif
