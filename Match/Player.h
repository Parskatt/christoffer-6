//
//Player.h
//

#ifndef PLAYER_H
#define PLAYER_H

//#include "Match.h"
#include "Character.h"

class Player
{
  public:

    Player() = default;

    Player(int);

    void send_key(int);

    Character get_curr_character();

  private:

    Character curr_character;
};

#endif
