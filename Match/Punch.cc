#include "Punch.h"


Punch::Punch(int width ,int height,int x,int y,int direction,Match & match)
    :Attack(width,height,x,y,direction,match,1)
{
    
}

Punch::get_texture_index()
{
    return texture_index;
}
