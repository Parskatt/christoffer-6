#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "../Object.h"
#include <string>

class Menu_Button : public Object
{
public:
  Menu_Button(int width ,int height,int x,int y,int index,std::string state);
  std::string get_state();
private:
  std::string state{};
};

class Play_Button : public Menu_Button
{
public:
  Play_Button(int width ,int height,int x,int y,int index);
};
class Instructions_Button : public Menu_Button
{
public:
  Instructions_Button(int width ,int height,int x,int y,int index);
};
class Quit_Button : public Menu_Button
{
public:
  Quit_Button(int width ,int height,int x,int y,int index);
};
#endif
