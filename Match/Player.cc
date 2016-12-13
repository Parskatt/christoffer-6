//
//Player.cc
//

#include "Player.h"

Player::Player(int player,int character)//-----------------------------------------------------
  :curr_character{}/*curr_character{character,player}*/, character_id{character}
{
  switch(character)
  {
    case 1:
    {
      //curr_character = Character{character,player}
      if(player == 1)
      {
        curr_character = Character{173,297,1000,350,{"Bilder/Krallex/KrallexStanceH04.png","Bilder/Krallex/KrallexStanceV04.png",
                                                     "Bilder/Krallex/KrallexHoppH11.png","Bilder/Krallex/KrallexHoppV11.png"},5,100,-1};
      }
      else
      {
      curr_character = Character{173,297,100,350,{"Bilder/Krallex/KrallexStanceH04.png","Bilder/Krallex/KrallexStanceV4.png",
                                                   "Bilder/Krallex/KrallexHoppH11.png","Bilder/Krallex/KrallexHoppV11.png"},5,100,1};
      }
    break;
   }
   case 2:
   {
     if(player == 1)
     {
       curr_character = Character{173,297,1000,350,{"Bilder/Kresper/KresperStanceH05.png","Bilder/Kresper/KresperStanceV05.png",
                                                   "Bilder/Kresper/KresperHoppH09.png","Bilder/Kresper/KresperHoppV09.png"},5,100,-1};
     }
     else
     {
       curr_character = Character{173,297,100,350,{"Bilder/Kresper/KresperStanceH05.png","Bilder/Kresper/KresperStanceV05.png",
                                                   "Bilder/Kresper/KresperHoppH09.png","Bilder/Kresper/KresperHoppV09.png"},5,100,1};
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
    //Gå ät vänster
    case 0:
    {
      curr_character.set_x_speed(-7);
      break;
    }
    //Gå åt höger
    case 1:
    {
      curr_character.set_x_speed(7);
      break;
    }
    //Hoppa
    case 2:
    {
      if (!curr_character.get_in_air() && !curr_character.get_is_stumped())
      {
        curr_character.set_y_speed(-27);
      }
      break;
    }
    //Slagattack
    case 3:
    {
    //  if (character_id == 1)
      //{
      curr_character.attack(character_id);      //curr_character.attack(1,character_id);
      //}
      break;
    }
  }
}

Character & Player::get_curr_character()
{
  return curr_character;
}
