#ifndef MENU_H
#define MENU_H

#include "../Object.h"
#include <SFML/Graphics.hpp>
#include "../Menu_Texture_handler.h"
#include "Play_Button.h"
#include <vector>
#include <string>

class Menu
{
private:

  std::string state{};
  std::vector<Object> main_buttons{};
  std::vector<Object> choose_char1_buttons{};
  std::vector<Object> choose_char2_buttons{};
  std::vector<Object> choose_playingfield_buttons{};
  std::vector<Object> show_instructions_buttons{};



public:

  Menu();

  void menu_loop();

  void main_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);
  
  void choose_char1_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

  void choose_char2_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

  void choose_playingfield_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

  void show_instructions_loop(sf::Clock &,sf::RenderWindow &,Menu_Texture_handler &, sf::Event &);

};

#endif
