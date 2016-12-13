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
    :Movable{width,height,x,y,il,speed,direction,1}, speed_vector{},health{health},
     curr_attack{}, has_attack{false},projectiles{},health_bar{health,direction},old_position{0,0} //health_bar{health,direction}
{
  /*
    if(player == 1)
    {
      direction = -1;
    }
    else
    {
      direction = 1;
    }

    switch(character)
    {
      case 1:
      {
        Character{173,297,1000,350,{"Bilder/cammy.png","Bilder/cammy1.png"},5,100,-1};


        break;
      }
      case 2:
      {

        break;
      }
      case 3:
      {

        break;
      }
      case 4:
      {

        break;
      }
    }*/
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

void Character::set_in_air(bool value)
{
  in_air = value;
}

Object::Position & Character::get_old_position()
{
  return old_position;
}


void Character::set_x_speed(int x_speed)
{
    speed_vector.x_speed = /*speed**/x_speed;
    direction = x_speed/abs(x_speed);    //inget abs innan
}

void Character::set_y_speed(int y_speed)
{
    speed_vector.y_speed = /*speed**/y_speed;
}

bool Character::get_in_air() const
{
  return in_air;
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
    old_position.xpos = position.xpos;
    old_position.ypos = position.ypos;

    position.xpos += speed_vector.x_speed;
    position.ypos += speed_vector.y_speed;
    speed_vector.x_speed = 0;
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
        if(direction == 1)
        {
    	     curr_attack = Punch{size.width,size.height,position.xpos + size.width,position.ypos,
             {"Bilder/Krallex/attans00.png","Bilder/Krallex/attans01.png","Bilder/Krallex/attans02.png",
             "Bilder/Krallex/attans03.png","Bilder/Krallex/attans04.png","Bilder/Krallex/attans05.png",
             "Bilder/Krallex/attans06.png","Bilder/Krallex/attans07.png","Bilder/Krallex/attans08.png",
             "Bilder/Krallex/attans09.png","Bilder/Krallex/attans10.png","Bilder/Krallex/attans11.png",
             "Bilder/Krallex/attans12.png","Bilder/Krallex/attans13.png","Bilder/Krallex/attans14.png",
             "Bilder/Krallex/attans15.png"}/*,"Bilder/Krallex/attans16.png","Bilder/Krallex/attans17.png",
             "Bilder/Krallex/attans18.png","Bilder/Krallex/attans19.png","Bilder/Krallex/attans20.png",
             "Bilder/Krallex/attans21.png","Bilder/Krallex/attans22.png","Bilder/Krallex/attans23.png",
             "Bilder/Krallex/attans24.png","Bilder/Krallex/attans25.png","Bilder/Krallex/attans26.png",
             "Bilder/Krallex/attans27.png","Bilder/Krallex/attans28.png","Bilder/Krallex/attans29.png",
             "Bilder/Krallex/attans30.png","Bilder/Krallex/attans31.png","Bilder/Krallex/attans32.png",*/
             //{"Bilder/Krallex/attans00.png","Bilder/Krallex/attans01.png","Bilder/Krallex/attans02.png"}
             ,direction,projectiles};//{"Bilder/cammy5.png","Bilder/cammy7.png","Bilder/cammy8.png"},direction,projectiles};
        }
        else
        {
          curr_attack = Punch{size.width,size.height,position.xpos,position.ypos,{"Bilder/cammy5.png","Bilder/cammy7.png","Bilder/cammy8.png"},direction,projectiles};
        }
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
  std::cout << health << std::endl;
  health = health - damage;
  std::cout << health << std::endl;
  if (health > 0)
  {
    health_bar.set_size(health);
  }
  else
  {
   health_bar.set_size(0);
  }
}
int Character::get_health()
{
  return health;
}
std::vector<Projectile> & Character::get_projectiles()
{
  return projectiles;
}
