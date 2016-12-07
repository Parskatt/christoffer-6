//
//Character.cc
//


#include "Character.h"
#include <iostream>
#include <utility>

/*Character::~Character()
{
  delete health_bar;
}*/

Character::Character(int width, int height,int x, int y,int index,int speed,int health,int direction)//---------------------------------------
    :Movable{width,height,x,y,index,speed,direction,1}, speed_vector{}, curr_attack{}, has_attack{false},projectiles{} //health_bar{health,direction}
{
    switch(direction)//Det här är fult, borde bara skicka in health och direction till healthbar så sätter den position
    {
      case 1:
      {
        health_bar = Health_bar{200,50,50,50,0,health,direction};
        break;
      }
      case -1:
      {
        health_bar = Health_bar{200,50,1230,50,0,health,direction};
        break;
      }
    }
    //Skapar och lägger till hälsomätaren i match's vector

    //nonmovable_objects.push_back(std::make_unique<Health_bar>(health_bar));//(200,50,50,50,3));
    //std::cout << "hej" << std::endl; //Behöver nog skicka in en direction också, så att vi kan spegla den för ena karaktären
    //health_bar = *nonmovable_objects.back();
    //std::cout << "då" << std::endl;//---------------------------------------------------------------------------------------
    //Jag förstår inte :'( - Kresper

    speed_vector.x_speed = 0;
    speed_vector.y_speed = 0;
    //curr_attack{} = nullptr;
}

/*Character & Character::operator=(const Character & other)
{
  size.width = other.size.width;
  size.height = other.size.height;
  position.xpos = other.position.xpos;
  position.ypos = other.position.ypos;
  texture_index = other.texture_index;
  speed = other.speed;
  direction = other.direction;
  fallable = other.fallable;
  curr_attack = std::move(other.curr_attack);
}*/

void Character::set_x_speed(int x_speed)
{
    speed_vector.x_speed = speed*x_speed;
    direction = x_speed;
}

void Character::set_y_speed(int y_speed)
{
    speed_vector.y_speed = speed*y_speed;
}

int Character::get_x_speed() const
{
    return speed_vector.x_speed;
}

int Character::get_y_speed() const
{
    return speed_vector.y_speed;
}

int Character::get_speed() const
{
    return speed;
}

void Character::move()
{
    //std::cout << "försöker mova" << std::endl;
    position.xpos += speed_vector.x_speed;
    position.ypos += speed_vector.y_speed;
    speed_vector.x_speed = 0;
    for (std::vector<Projectile>::iterator it = projectiles.begin() ; it != projectiles.end(); ++it)
    {
      it->move();
    }
    //std::cout << "hej";
}

void Character::move(int step_direction)
{
  position.xpos += step_direction*speed_vector.x_speed;
  position.ypos += step_direction*speed_vector.y_speed;
}

void Character::render(sf::RenderWindow & window, Texture_handler & table) //Borde hantera textures på nåt annat sätt om vi ska ha render här
{
  if(!has_attack)
  {
    if(direction == 1)
    {
      sf::Sprite sprite{};
      sprite.setTexture(table.get_texture(texture_index + 2));
      sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
      window.draw(sprite);
    }
    else
    {
      sf::Sprite sprite{};
      sprite.setTexture(table.get_texture(texture_index));
      sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
      window.draw(sprite);
    }
  }
  else
  {
   if(curr_attack.done())
    {
      has_attack = false;
      sf::Sprite sprite{};
      sprite.setTexture(table.get_texture(texture_index));
      sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
      window.draw(sprite);
    }
    else
    {
      curr_attack.set_xpos(position.xpos);
      curr_attack.set_ypos(position.ypos);
      curr_attack.render(window,table);
    }
  }
  for (std::vector<Projectile>::iterator it = projectiles.begin() ; it != projectiles.end(); ++it)
  {
    it->render(window,table);
  }
  health_bar.render(window,table);
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

void Character::attack(int attack_type)
{
    if(!has_attack)
    {
    	if(attack_type == 1)
    	{
    	  curr_attack = Punch{size.width,size.height,position.xpos,position.ypos,3,direction,projectiles};
        has_attack = true;
    	}
    }
    else
    {
      if(curr_attack.done())
      {
        curr_attack = Punch{size.width,size.height,position.xpos,position.ypos,3,direction,projectiles};
      }
    }
}

void Character::lose_health(int damage)
{
  health -= damage;
  health_bar.set_size(health);
}
