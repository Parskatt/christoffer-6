//
//Projectile.cc
/

#include "Projectile.h"

Projectile::Projectile(int width,int height,int x,int y,int index,int speed,int direction,int damage)
    :Movable{width,height,x,y,index,speed,direction,0}, damage{damage}
{

}


Projectile move()
{
  pos.xpos += direction * speed;
}


#include Punch_projectile.h

Punch_projectile::Punch_projectile(int width,int height,int x,int y,int index,int speed,int direction,int damage,int range)
    :Projectile{width,height,x,y,index,speed,direction,damage}, range{range}
{

}

int Punch_projectile::get_range()
{
  return range;
}
