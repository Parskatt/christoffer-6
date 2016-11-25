//
//Character.cc
//


#include "Character.h"

Character::Character(int width, int height,int x, int y,int index,int speed,int health,int direction)
    :Movable{width,height,x,y,index,speed,direction,1}, speed_vector{}, health_bar{}
{
    speed_vector.x_speed = 0;
    speed_vector.y_speed = 0;
    //curr_attack{} = nullptr;
}

void Character::set_x_speed(int x_speed)
{
    speed_vector.x_speed = x_speed;
}

void Character::set_y_speed(int y_speed)
{
    speed_vector.y_speed = y_speed;
}

int Character::get_x_speed() const
{
    return speed_vector.x_speed;
}

int Character::get_y_speed() const
{
    return speed_vector.y_speed;
}

int Character::get_speed()
{
    return speed;
}

void Character::move()
{
    pos.xpos = pos.xpos + speed_vector.x_speed;
    pos.ypos = pos.ypos + speed_vector.y_speed;
}

/*void Character::jump()
{

}*/
/*
int Character::get_texture_index() override
{
    if(curr_attack != nullptr)
    {
	     return curr_attack->get_texture_index();
    }
    else
    {
	     return texture_index;
    }
}
*/
/*
void Character::attack(int attack_type,Match & match)
{
    if(curr_attack == nullptr)
    {
    	if(attack_type == 1)
    	{
    	    curr_attack = new Punch{Size.width,Size.height,Position.xpos,Position.ypos
    				    ,direction,match};
    	}
    }
}
*/
void Character::lose_health(int damage)
{
  health -= damage;
}
