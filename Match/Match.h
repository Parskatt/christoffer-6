/*
*Match.h
*/

#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics.hpp>
#include "Non_movables.h"
#include "../Texture_handler.h"
//#include "Object.h"
//#include "Movable.h"
//#include "Physics_engine.h"
//#include "Player.h"
#include <vector>

class Match
{
  public:
    Match(int character1, int character2, int playing_field);

    ~Match()=default;

    //Playing_field make_playingfield(int); //bEHÖVER VI GÖRA SÅ?
    //Character make_character(int);

    void run();

    void graphic_update(sf::Clock &,sf::RenderWindow &,Texture_handler &);

    void keyboard_handler();

    //void position_update(Object object);

    //void collision_update(Object object);

    //void position_update();

    //bool dead_check();


  protected:
    //std::vector<Movable> movable_objects{};
    std::vector<Object> nonmovable_objects{};

    //Player player1{};
    //Player player2{};

    std::vector<sf::Keyboard> p1_commands{};
    std::vector<sf::Keyboard> p2_commands{};

    //Physics_engine physics_engine{};

    Playing_field playing_field;

};

#endif
