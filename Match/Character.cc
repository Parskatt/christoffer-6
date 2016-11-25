//
//Character.cc
//


#include "Character.h"

Character::Character(int width, int height,int x, int y,int index,int speed,int health,int direction)
    :Movable{width,height,x,y,index,speed,direction,1}, Speed_vector{}, health_bar{};
{
    Speed_vector.x_speed = 0;
    Speed_vector.y_speed = 0;
    curr_attack{} = nullptr;
}

void set_x_speed(int x_speed)
{
    Speed_vector.x_speed = x_speed
}

void set_y_speed(int y_speed)
{
    Speed_vector.y_speed = y_speed
}

int get_x_speed() const
{
    return Speed_vector.x_speed;
}

int get_y_speed() const
{
    return Speed_vector.y_speed;
}

int get_speed()
{
    return Speed;
}

void move()
{
    Position.xpos = Position.xpos + Speed_vector.x_speed;
    Position.ypos = Position.ypos + Speed_vector.y_speed;
}

void jump()
{

}

int get_texture_index() override
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

void attack(int attack_type,Match match)
{
    if(curr_attack == nullptr)
    {
	if(attack_type == 1)
	{
	    curr_attack = new Punch{int Size.width, int Size.height, int Position.xpos, int Position.ypos
				    ,int direction,Match match};
	}
    }
}

void lose_health(int)
{

}
