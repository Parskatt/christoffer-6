/*
*Match.h
*/

#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics.hpp>
#include "Non_movables.h"
#include "../Texture_handler.h"
//#include "../Object.h"
//#include "Movable.h"
//#include "Physics_engine.h"
#include "Player.h"
#include <vector>
#include <memory>
#include "Physics_engine.h"

class Match
{
  public:
    Match(int character1, int character2, std::initializer_list<std::string>);

    ~Match() = default;

    void run();

    void graphic_update(sf::Clock &,sf::RenderWindow &);

    void keyboard_handler(sf::RenderWindow &, sf::Event &, bool &);

    //void position_update(std::unique_ptr<Movable> &);//-----------------------------------------------------------

    //void collision_update(Object object);

    void position_update(Physics_engine &, bool &);

    //bool dead_check();


  protected:
    //std::vector<std::unique_ptr<Movable>> movable_objects{}; //Kanske ska vara en vektor med unique_ptrs------------------------------------
    //std::vector<std::unique_ptr<Object>> nonmovable_objects{};

    Playing_field playing_field; //Behövs väl egentligen inte
    Player player1{};
    Player player2{};

    std::vector<sf::Keyboard::Key> p1_commands{};
    std::vector<sf::Keyboard::Key> p2_commands{};

    //Physics_engine physics_engine{};


};

#endif
