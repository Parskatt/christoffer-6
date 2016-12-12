#include "Menu_Button.h"

Menu_Button::Menu_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il,std::string state)
:Object{width,height,x,y,il}, state{state}
{}

std::string Menu_Button::get_state()
{
  return state;
}

bool Menu_Button::inside_button(int x, int y)
{
  return !(x > limit.right || x < limit.left || y > limit.lower || y < limit.upper);
}
void Menu_Button::render(sf::RenderWindow &)
{}

Play_Button::Play_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"char1"}
{}

Instructions_Button::Instructions_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"instructions"}
{}

Quit_Button::Quit_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"quit"}
{}

FattigJohan_Button::FattigJohan_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"FattigJohan"}
{}

Kresper_Button::Kresper_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"Kresper"}
{}

Krallex_Button::Krallex_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"Krallex"}
{}

Kraxel_Button::Kraxel_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"Kraxel"}
{}

Instructionsloop_Button::Instructionsloop_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"main"}
{}

Playingfield_Button::Playingfield_Button(int width ,int height,int x,int y,std::initializer_list<std::string> il)
:Menu_Button{width,height,x,y,il,"kappa"}
{}
