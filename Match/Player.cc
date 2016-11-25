//
//Player.cc
//

#include "Player.h"

Player::Player(int character)//, Match & match)
{
  switch(character)
  {
    case 1:
    {
      curr_character = Character{100,100,600,350,2,10,100,1};
      //match.nonmovable_objects.push_back(curr_character);
      break;
    }
    default:
      //curr_character = Character{1,1,1,1,1}//,match};
  }
}

Player::send_key(int key) //Borde va enum
{
  switch(key)
  {
    //Gå ät vänster
    case 1:
    {
      curr_character.set_x_speed(-1);
      break;
    }
    //Gå åt höger
    case 2:
    {
      curr_character.set_x_speed(1);
      break;
    }
    //Hoppa
    case 3:
    {
      //curr_character.jump();
      break;
    }
    //Ducka??????
    case 4:
    {
      break;
    }
    //Slagattack
    case 5:
    {
      //curr_character.attack(1);
      break;
    }
  }

}
Character Player::get_curr_character()
{
  return curr_character;
}
