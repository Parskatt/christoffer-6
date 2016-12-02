//
//Player.h
//

#ifndef PLAYER_H
#define PLAYER_H

//#include "Match.h"
#include "Character.h"
#include <memory>
#include <SFML/Graphics.hpp>

class Player
{
  public:

    Player() = default;

    Player(int);//-----------------------------------------------------------

    void send_key(int);

    void render(sf::RenderWindow &, Texture_handler &);

    void position_update();

    //Character & get_curr_character();

  private:

    Character curr_character;
    //int curr_character;
};

#endif
