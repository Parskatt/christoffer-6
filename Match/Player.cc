//
//Player.cc
//

#include "Player.h"

Player::Player(int character,int player)//-----------------------------------------------------
  :curr_character{}, character_id{character}
{
  switch(player)
  {
    case 1:
    {
      curr_character = Character{100,100,600,350,{"Bilder/cammy.png","Bilder/cammy1.png"},5,100,-1};
      //movable_objects.push_back(std::make_unique<Character>(curr_character));//(100,100,600,350,2,5,100,1,nonmovable_objects));

      //curr_character = *dynamic_cast<Character*>(movable_objects.back());

      //curr_character = (new Character{100,100,600,350,2,5,100,1,nonmovable_objects});
      //movable_objects.push_back(curr_character);//-----------------------------------------------------------------
    break;
    }
    case 2:
    {
      curr_character = Character{100,100,100,350,{"Bilder/cammy.png","Bilder/cammy1.png"},5,100,1};
      break;
    }
    //default:
      //curr_character = (new Character{100,100,600,350,2,10,100,1,nonmovable_objects});
      //movable_objects.push_back(curr_character);
  }
}

void Player::render(sf::RenderWindow & window)
{
  curr_character.render(window);
}

void Player::position_update()
{
  curr_character.move();
}

void Player::send_key(int key) //Borde va enum
{
  switch(key)
  {
    //Gå ät vänster
    case 0:
    {
      curr_character.set_x_speed(-1);
      break;
    }
    //Gå åt höger
    case 1:
    {
      curr_character.set_x_speed(1);
      break;
    }
    //Hoppa
    case 2:
    {
      curr_character.set_y_speed(-1);
      break;
    }
    //Ducka??????
    case 3:
    {
      //curr_character.lose_health(5);
      if (character_id == 1)
      {
      curr_character.attack(1,1);
      }
      break;
    }
    //Slagattack
  /*  case 4:
    {
      curr_character.has_attack = true;
      curr_character.attack(1);
      break;
    }*/
  }

}
/*
Character & Player::get_curr_character()
{
  return curr_character;
}
*/
