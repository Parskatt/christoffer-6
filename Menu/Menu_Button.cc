#include "Menu_Button.h"

Menu_Button::Menu_Button(int width ,int height,int x,int y,int index,std::string state)
:Object{width,height,x,y,index}, state{state}
{}

std::string Menu_Button::get_state()
{
  return state;
}

Play_Button::Play_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"char1"}
{}

Instructions_Button::Instructions_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"instructions"}
{}

Quit_Button::Quit_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"quit"}
{}

FattigJohan_Button::FattigJohan_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"FattigJohan"}
{}

Kresper_Button::Kresper_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"Kresper"}
{}

Krallex_Button::Krallex_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"Krallex"}
{}

Kraxel_Button::Kraxel_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"Kraxel"}
{}

Instructionsloop_Button::Instructionsloop_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"main"}
{}

Playingfield_Button::Playingfield_Button(int width ,int height,int x,int y,int index)
:Menu_Button{width,height,x,y,index,"match"}
{}
