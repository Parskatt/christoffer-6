/*
*Match.h
*/

#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics.hpp>
#include "Non_movables.h"
#include "../Texture_handler.h"
#include "Player.h"
#include <vector>
#include <memory>
#include "Physics_engine.h"

class Match
{
  public:
    Match(int character1, int character2, int playing_field);

    ~Match() = default;

    void run();

    void graphic_update(sf::Clock &,sf::RenderWindow &);

    void keyboard_handler(sf::RenderWindow &, sf::Event &, bool &);

    void position_update(Physics_engine &, bool &);

    void is_dead(bool &, sf::RenderWindow &);


  protected:

    Playing_field playing_field;
    Player player1{};
    Player player2{};

    std::vector<sf::Keyboard::Key> p1_commands{};
    std::vector<sf::Keyboard::Key> p2_commands{};


};

#endif
