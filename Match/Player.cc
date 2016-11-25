//
//Player.cc
//

#include "Player.h"

Player::Player(int char)
{
  switch(char)
  {
    case 1:
    {
      curr_character = Character{1,1,1,1,1};
      break;
    }
    default:
      curr_character = Character{1,1,1,1,1};
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
      curr_character.jump();
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
      curr_character.attack(1);
      break;
    }
  }

}
