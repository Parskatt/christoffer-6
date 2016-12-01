//
//Player.cc
//

#include "Player.h"

Player::Player(int character,std::vector<Movable*> & movable_objects, std::vector<Object*> & nonmovable_objects)//-----------------------------------------------------
  :curr_character{}
{
  switch(character)
  {
    case 1:
      curr_character = (new Character{100,100,600,350,2,5,100,1,nonmovable_objects});
      movable_objects.push_back(curr_character);//-----------------------------------------------------------------
      break;
    default:
      curr_character = (new Character{100,100,600,350,2,10,100,1,nonmovable_objects});
      //movable_objects.push_back(curr_character);
  }
}

void Player::send_key(int key) //Borde va enum
{
  switch(key)
  {
    //Gå ät vänster
    case 0:
    {
      curr_character->set_x_speed(-1);
      break;
    }
    //Gå åt höger
    case 1:
    {
      curr_character->set_x_speed(1);
      break;
    }
    //Hoppa
    case 2:
    {
      curr_character->set_y_speed(-1);
      break;
    }
    //Ducka??????
    case 3:
    {
      //curr_character.attack();
      break;
    }
    //Slagattack
    case 4:
    {
      //curr_character.attack(1);
      break;
    }
  }

}
/*
Character Player::get_curr_character()
{
  return curr_character;
}*/
