#ifndef MENU_H
#define MENU_H

#include "../Object.h"
#include <SFML/Graphics.hpp>
#include "../Menu_Texture_handler.h"
#include "Menu_Button.h"
#include "Menu_Text.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <SFML/Audio.hpp>
#include <initializer_list>

class Menu
{
private:

  std::string state{};
  std::vector<Menu_Button> main_buttons{};
  std::vector<Menu_Button> choose_char1_buttons{};
  std::vector<Menu_Button> choose_char2_buttons{};
  std::vector<Menu_Button> choose_playingfield_buttons{};
  std::vector<Menu_Button> show_instructions_buttons{};
  std::vector<Menu_Text> show_character_texts{};
  Menu_Text show_instructions_text;
  std::string char1{};
  std::string char2{};
  std::string playingfield{};


public:

  Menu();

  void menu_loop(bool &);

  bool main_loop(sf::Clock &,sf::RenderWindow &, sf::Event &);

  bool choose_char1_loop(sf::Clock &,sf::RenderWindow &, sf::Event &);

  bool choose_char2_loop(sf::Clock &,sf::RenderWindow &, sf::Event &);

  bool choose_playingfield_loop(sf::Clock &,sf::RenderWindow &, sf::Event &);

  bool show_instructions_loop(sf::Clock &,sf::RenderWindow &, sf::Event &);

  void draw_sprite(std::vector<Menu_Button>::iterator &,sf::RenderWindow &,int);

  void krallex_pick(sf::RenderWindow &,sf::Event &);

  int get_char1();
  int get_char2();
  int get_playingfield();

};

#endif
