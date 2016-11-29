#ifndef MENU_H
#define MENU_H

#include "../Object.h"
#include <SFML/Graphics.hpp>
#include "../Menu_Texture_handler.h"
#include "Menu_Button.h"
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

class Menu
{
private:

  std::string state{};
  std::vector<Menu_Button> main_buttons{};
  std::vector<Menu_Button> choose_char1_buttons{};
  std::vector<Menu_Button> choose_char2_buttons{};
  std::vector<Menu_Button> choose_playingfield_buttons{};
  std::vector<Menu_Button> show_instructions_buttons{};
  std::string char1{};
  std::string char2{};
  std::string playingfield{};


public:

  Menu();

  void menu_loop();

  bool main_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

  void choose_char1_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

  void choose_char2_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

  void choose_playingfield_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

  void show_instructions_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

};

#endif
