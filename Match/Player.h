//
//Player.h
//

#ifndef PLAYER_H
#define PLAYER_H

//#include "Match.h"
#include "Character.h"
#include <memory>

class Player
{
  public:

    Player() = default;

    Player(int, std::vector<std::unique_ptr<Movable>> &,std::vector<std::unique_ptr<Object>> &);//-----------------------------------------------------------

    void send_key(int);

    //Character & get_curr_character();

  private:

    Character curr_character;
    //int curr_character;
};

#endif
