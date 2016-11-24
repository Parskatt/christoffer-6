#include "Character.h"

Character::Character(int width, int height,int x, int y,int index,int speed,int health,int direction)
    :Movable{width,height,x,y,index,speed,direction,1}, Speed_vector{}, health_bar{};
{
    Speed_vector.x_speed = 0;
    Speed_vector.y_speed = 0;
    curr_attack{} = nullptr;
}
