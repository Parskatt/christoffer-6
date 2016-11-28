#include "Menu.h"
#include <iostream>



Menu::Menu()
:state{"main"},main_buttons{}, choose_char1_buttons{}, choose_char2_buttons{}, choose_playingfield_buttons{}, show_instructions_buttons{}
{}





void Menu::menu_loop()
{
  Menu_Texture_handler handler{};
  bool running{true};
  sf::Event event;
  sf::Clock clock;
  sf::Time targetFrameDelay {sf::milliseconds(10)};
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window{sf::VideoMode{1280,720},"SFML Test", sf::Style::Default, settings};

  while(state != "quit" && state != "match" && running == true)
  {
    if(state == "main")
    {
      Play_Button Play{500,500,500,500,0};
      main_buttons.push_back(Play);
      main_loop(clock,window,handler,event);
    }/*
    else if(state == "char1")
    {
      choose_char1_loop(clock,window,handler,event);
    }
    else if(state == "char2")
    {
      choose_char2_loop(clock,window,handler,event);
    }
    else if(state == "playingfield")
    {
      choose_playingfield_loop(clock,window,handler,event);
    }
    else if(state == "instructions")
    {
      show_instructions_loop(clock,window,handler,event);
    }*/
    auto frameDelay = clock.getElapsedTime();
    if ( targetFrameDelay > frameDelay )
    {
        // only wait if it is actually needed
        auto sleepTime = targetFrameDelay - frameDelay;
        sf::sleep(sleepTime);
    }
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        running = false;
    }
  }
  if(state == "quit")
  {}
}

void Menu::main_loop(sf::Clock & clock,sf::RenderWindow & window, Menu_Texture_handler & table,sf::Event & event)
{
  //auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  for(std::vector<Object>::iterator it = main_buttons.begin() ; it != main_buttons.end(); ++it)
  {
    sf::Sprite sprite{};
    sprite.setTexture(table.get_texture(it->get_texture_index()));
    sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
    window.draw(sprite);
  }
  window.display();
}
