/*
*Match.h
*/

#ifndef MATCH.H
#define MATCH.H

#include "Playing_field"
#include "Physics_engine"
#include "Player"
#include <vector>

class Match
{
  public:
    Match(int character1, int character2, int playing_field);

    ~Match()=default;

    void graphic_update();

    void keyboard_handler();

    void position_update(Object object);

    void collision_update(Object object);

    void position_update();

    bool dead_check();

  protected:
    std::vector movable_objects{};
    std::vector nonmovable_objects{};

    Player player1{};
    Player player2{};

    std::string p1_commands{};
    std::string p2_commands{};

    Physics_engine physics_engine{};

    Playing_field playing_field{};

}
