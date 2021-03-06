#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "../Object.h"
#include <string>

class Menu_Button : public Object
{
public:

  Menu_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il,std::string state);

  std::string get_state();

  void render(sf::RenderWindow &) override;

  void render(sf::RenderWindow &,int);

  bool inside_button(int x, int y);

private:

  std::string state{};
};
//main buttons
class Play_Button : public Menu_Button
{
public:
  Play_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

class Instructions_Button : public Menu_Button
{
public:
  Instructions_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

class Quit_Button : public Menu_Button
{
public:
  Quit_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

//choose_char1
class FattigJohan_Button : public Menu_Button
{
public:
  FattigJohan_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

class Kresper_Button : public Menu_Button
{
public:
  Kresper_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

class Krallex_Button : public Menu_Button
{
public:
  Krallex_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

class Kraxel_Button : public Menu_Button
{
public:
  Kraxel_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

class Instructionsloop_Button : public Menu_Button
{
public:
  Instructionsloop_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

class Playingfield_Button1 : public Menu_Button
{
public:
  Playingfield_Button1(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};
class Playingfield_Button2 : public Menu_Button
{
public:
  Playingfield_Button2(int width ,int height,int x,int y,std::initializer_list<std::string> il);
};

#endif
