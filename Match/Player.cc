//
//Player.cc
//

#include "Player.h"

Player::Player(int player,int character)
  :curr_character{}, character_id{character}
{
  switch(character)
  {
    case 1:
    {
      if(player == 1)
      {
        curr_character = Character{100,297,1000,100,{"Bilder/Krallex/KrallexStanceH04.png","Bilder/Krallex/KrallexStanceV04.png",
                                                     "Bilder/Krallex/KrallexHoppH11.png","Bilder/Krallex/KrallexHoppV11.png"},100,-1};
      }
      else
      {
      curr_character = Character{100,297,100,100,{"Bilder/Krallex/KrallexStanceH04.png","Bilder/Krallex/KrallexStanceV04.png",
                                                   "Bilder/Krallex/KrallexHoppH11.png","Bilder/Krallex/KrallexHoppV11.png"},100,1};
      }
    break;
   }
   case 2:
   {
     if(player == 1)
     {
       curr_character = Character{100,297,1000,100,{"Bilder/Kresper/KresperStanceH05.png","Bilder/Kresper/KresperStanceV05.png",
                                                   "Bilder/Kresper/KresperHoppH09.png","Bilder/Kresper/KresperHoppV09.png"},100,-1};
     }
     else
     {
       curr_character = Character{100,297,100,100,{"Bilder/Kresper/KresperStanceH05.png","Bilder/Kresper/KresperStanceV05.png",
                                                   "Bilder/Kresper/KresperHoppH09.png","Bilder/Kresper/KresperHoppV09.png"},100,1};
     }

      break;

   }
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

void Player::stopwalking()
{
  curr_character.set_x_speed(0);
}

void Player::send_key(int key) //Borde va enum
{
  switch(key)
  {
    //Go left
    case 0:
    {
      if(!curr_character.has_attack)
      {
      curr_character.set_x_speed(-7);
      }
      break;
    }
    //Go right
    case 1:
    {
      if(!curr_character.has_attack)
      {
      curr_character.set_x_speed(7);
      }
      break;
    }
    //Jump
    case 2:
    {
      if (!curr_character.get_in_air() && !curr_character.get_is_stumped())
      {
        curr_character.set_y_speed(-27);
      }
      break;
    }
    //Punch
    case 3:
    {
      curr_character.attack(character_id);      //curr_character.attack(1,character_id);
      break;
    }
  }
}

Character & Player::get_curr_character()
{
  return curr_character;
}
