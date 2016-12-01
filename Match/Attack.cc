//
//Attack.cc
//

#include "Attack.h"

Attack::Attack(int width,int height,int x,int y,int index)
    :Object{width,height,x,y,index}
{

}






Punch::Punch(int width,int height,int x,int y,int index)
    :Attack(width,height,x,y,index)
{
 curr_projectile = new Punch_projectile{20,20,?,?,nåt index};

}
