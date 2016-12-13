//
//Character.cc
//


#include "Character.h"
#include <iostream>
#include <utility>


Character::Character(int width, int height,int x, int y,std::initializer_list<std::string> il,int speed,int health,int direction)//---------------------------------------
    :Movable{width,height,x,y,il,speed,direction,1}, speed_vector{0,0},health{health},
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

void Character::set_is_stumped(bool value)
{
  is_stumped = value;
}

Object::Position & Character::get_old_position()
{
  return old_position;
}


void Character::set_x_speed(int x_speed)
{
    speed_vector.x_speed = x_speed;
    direction = x_speed/abs(x_speed);
}

void Character::set_y_speed(int y_speed)
{
    speed_vector.y_speed = y_speed;
}

bool Character::get_in_air() const
{
  return in_air;
}

bool Character::get_is_stumped() const
{
  return is_stumped;
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

/*void Character::move(int step_direction)
{
  std::cout << "move-1" << std::endl;
  if (speed_vector.x_speed != 0)
  {
    std::cout << "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK" << std::endl;
  }

  position.xpos += step_direction*speed_vector.x_speed;
  position.ypos += step_direction*speed_vector.y_speed;
  update_limits();
}*/

void Character::render(sf::RenderWindow & window)
{
  if(!has_attack)
  {
    if(in_air)
    {
      if(direction == 1)
      {
        sf::Sprite sprite{};
        sprite.setTexture(texture_handler.get_texture(2));
        sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
        window.draw(sprite);
      }
      else
      {
        sf::Sprite sprite{};
        sprite.setTexture(texture_handler.get_texture(3));
        sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
        window.draw(sprite);
      }
    }
    else
    {
      if(direction == 1)
      {
        sf::Sprite sprite{};
        sprite.setTexture(texture_handler.get_texture(0));
        sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
        window.draw(sprite);
      }
      else
      {
        sf::Sprite sprite{};
        sprite.setTexture(texture_handler.get_texture(1));
        sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
        window.draw(sprite);
      }
    }
  }
    else
    {
     if(curr_attack.done())
      {
        has_attack = false;
        /*sf::Sprite sprite{};
        sprite.setTexture(texture_handler.get_texture(0));
        sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
        window.draw(sprite);*/
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

void Character::attack(int character_id)  //(int attack_type,int character_id)
{
    if(!has_attack)
    {
      if(character_id ==1)
      {
        if(direction == 1)
        {
    	     curr_attack = Punch{size.width,size.height,position.xpos + size.width,position.ypos,
             {"Bilder/Krallex/KrallexSparkH00.png", "Bilder/Krallex/KrallexSparkH01.png", "Bilder/Krallex/KrallexSparkH02.png", "Bilder/Krallex/KrallexSparkH03.png",
              "Bilder/Krallex/KrallexSparkH04.png", "Bilder/Krallex/KrallexSparkH05.png", "Bilder/Krallex/KrallexSparkH06.png", "Bilder/Krallex/KrallexSparkH07.png",
              "Bilder/Krallex/KrallexSparkH08.png", "Bilder/Krallex/KrallexSparkH09.png"},
              direction,projectiles};
        }
        else
        {
          curr_attack = Punch{size.width,size.height,position.xpos,position.ypos,
            {"Bilder/Krallex/KrallexSparkV00.png", "Bilder/Krallex/KrallexSparkV01.png", "Bilder/Krallex/KrallexSparkV02.png", "Bilder/Krallex/KrallexSparkV03.png",
             "Bilder/Krallex/KrallexSparkV04.png", "Bilder/Krallex/KrallexSparkV05.png", "Bilder/Krallex/KrallexSparkV06.png", "Bilder/Krallex/KrallexSparkV07.png",
             "Bilder/Krallex/KrallexSparkV08.png", "Bilder/Krallex/KrallexSparkV09.png"},
             direction,projectiles};
        }
        has_attack = true;
      }
    else
    {
      if(direction == 1)
      {
        curr_attack = Punch{size.width,size.height,position.xpos + size.width/2,position.ypos,
          {"Bilder/Kresper/KresperSlagH00.png", "Bilder/Kresper/KresperSlagH01.png", "Bilder/Kresper/KresperSlagH02.png", "Bilder/Kresper/KresperSlagH03.png",
           "Bilder/Kresper/KresperSlagH04.png", "Bilder/Kresper/KresperSlagH05.png", "Bilder/Kresper/KresperSlagH06.png", "Bilder/Kresper/KresperSlagH07.png",
           "Bilder/Kresper/KresperSlagH08.png", "Bilder/Kresper/KresperSlagH09.png"},
          direction,projectiles};
      }
      else
      {
        curr_attack = Punch{size.width,size.height,position.xpos + size.width/2,position.ypos,
          {"Bilder/Kresper/KresperSlagV00.png", "Bilder/Kresper/KresperSlagV01.png", "Bilder/Kresper/KresperSlagV02.png", "Bilder/Kresper/KresperSlagV03.png",
           "Bilder/Kresper/KresperSlagV04.png", "Bilder/Kresper/KresperSlagV05.png", "Bilder/Kresper/KresperSlagV06.png", "Bilder/Kresper/KresperSlagV07.png",
           "Bilder/Kresper/KresperSlagV08.png", "Bilder/Kresper/KresperSlagV09.png"},
          direction,projectiles};
      }
      has_attack = true;
    }
  }
}
  /*  else
    {
      if(curr_attack.done())
      {
        curr_attack = Punch{size.width,size.height,position.xpos,position.ypos,{"Bilder/cammy5.png","Bilder/cammy7.png","Bilder/cammy8.png"},direction,projectiles};
      }
    }
}*/

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
