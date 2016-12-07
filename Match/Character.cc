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

Character::Character(int width, int height,int x, int y,std::initializer_list<std::string> il,int speed,int health,int direction)//---------------------------------------
    :Movable{width,height,x,y,il,speed,direction,1}, speed_vector{}, curr_attack{}, has_attack{false},projectiles{} //health_bar{health,direction}
{
    switch(direction)//Det här är fult, borde bara skicka in health och direction till healthbar så sätter den position
    {
      case 1:
      {
        health_bar = Health_bar{200,50,50,50,{"Bilder/tom.png"},health,direction};
        break;
      }
      case -1:
      {
        health_bar = Health_bar{200,50,1230,50,{"Bilder/tom.png"},health,direction};
        break;
      }
    }
    //Skapar och lägger till hälsomätaren i match's vector

//---------------------------------------------------------------------------------------
    //Jag förstår inte :'( - Kresper

    speed_vector.x_speed = 0;
    speed_vector.y_speed = 0;
    //curr_attack{} = nullptr;
}

void Character::set_x_pos(int xposition)
{
  position.xpos = xposition;
}

void Character::set_y_pos(int yposition)
{
  position.ypos = yposition;
}



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
    position.xpos += speed_vector.x_speed;
    position.ypos += speed_vector.y_speed;
    //speed_vector.x_speed = 0;
    for (std::vector<Projectile>::iterator it = projectiles.begin() ; it != projectiles.end(); ++it)
    {
      if(it->done())
      {
        projectiles.erase(it);
        --it;
      }
      else
      {
      it->move();
    }
    }
    update_limits();
}

void Character::move(int step_direction)
{
  std::cout << "move-1" << std::endl;
  if (speed_vector.x_speed != 0)
  {
    std::cout << "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK" << std::endl;
  }

  position.xpos += step_direction*speed_vector.x_speed;
  position.ypos += step_direction*speed_vector.y_speed;
  update_limits();
}

void Character::render(sf::RenderWindow & window)
{
  if(!has_attack)
  {
    if(direction == 1)
    {
      sf::Sprite sprite{};
      sprite.setTexture(texture_handler.get_texture(1));
      sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
      window.draw(sprite);
    }
    else
    {
      sf::Sprite sprite{};
      sprite.setTexture(texture_handler.get_texture(0));
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
      sprite.setTexture(texture_handler.get_texture(0));
      sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
      window.draw(sprite);
    }
    else
    {
      curr_attack.set_xpos(position.xpos);
      curr_attack.set_ypos(position.ypos);
      curr_attack.render(window);
    }
  }
  for (std::vector<Projectile>::iterator it = projectiles.begin() ; it != projectiles.end(); ++it)
  {
    it->render(window);
  }
  health_bar.render(window);
}

void Character::attack(int attack_type,int character_id)
{
    if(!has_attack)
    {
    	if(attack_type == 1)
    	{
    	  curr_attack = Punch{size.width,size.height,position.xpos,position.ypos,{"Bilder/cammy5.png","Bilder/cammy7.png","Bilder/cammy8.png"},direction,projectiles};
        std::cout << "skapar attack" << std::endl;
        has_attack = true;
    	}
    }
    else
    {
      if(curr_attack.done())
      {
        curr_attack = Punch{size.width,size.height,position.xpos,position.ypos,{"Bilder/cammy5.png","Bilder/cammy7.png","Bilder/cammy8.png"},direction,projectiles};
      }
    }
}

void Character::lose_health(int damage)
{
  health -= damage;
  health_bar.set_size(health);
}

std::vector<Projectile> & Character::get_projectiles()
{
  return projectiles;
}
