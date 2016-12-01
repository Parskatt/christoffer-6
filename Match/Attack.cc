//
//Attack.cc
//

#include "Attack.h"
#include time

Attack::Attack(int width,int height,int x,int y,int index,int direction)
    :Object{width,height,x,y,index}
{

}


void Attack::wait()
{
  sleep(1);
  delete curr_projectile;
}





Punch::Punch(int width,int height,int x,int y,int index,int direction)
    :Attack(width,height,x,y,index)
{
 curr_projectile = new Punch_projectile{20,20,?,?,nåt index,direction,damage};

}
