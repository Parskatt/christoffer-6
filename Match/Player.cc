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
      curr_character.set_x_speed(-1)
      break;
    }

    case 1:
    {
      break;
    }

    case 1:
    {
      break;
    }

    case 1:
    {
      break;
    }

    case 1:
    {
      break;
    }



  }

}
