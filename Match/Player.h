//
//Player.h
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player
{
  public:

    Player(int);

    void send_key(int);

  private:

    Character curr_character;
};

#endif
