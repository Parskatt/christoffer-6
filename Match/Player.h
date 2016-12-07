//
//Player.h
//

#ifndef PLAYER_H
#define PLAYER_H

//#include "Match.h"
#include "Character.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
  public:

    Player() = default;

    Player(int,int);//-----------------------------------------------------------

    void send_key(int);

    void render(sf::RenderWindow &);

    void position_update();

    Character & get_curr_character();

  private:

    Character curr_character;
    int character_id;
};

#endif
