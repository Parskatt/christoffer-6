#include "Menu.h"
#include <iostream>



Menu::Menu()
:state{"main"},main_buttons{}, choose_char1_buttons{}, choose_char2_buttons{}, choose_playingfield_buttons{}, show_instructions_buttons{}
{}





void Menu::menu_loop()
{
  sf::Music music;
  if (!music.openFromFile("Menu/BackgroundMusic.wav"))
    {
      std::cout << "attans grabbar!";
    } // error
  music.play();

  Menu_Texture_handler handler{};
  bool running{true};
  sf::Event event;
  sf::Clock clock;
  sf::Time targetFrameDelay {sf::milliseconds(100)};
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window{sf::VideoMode{1280,720},"SFML Test", sf::Style::Default, settings};
  Play_Button Play{320,100,480,210,0};
  Instructions_Button Instructions{320,100,480,310,1};
  Quit_Button Quit{320,100,480,410,2};
  main_buttons.push_back(Play);
  main_buttons.push_back(Instructions);
  main_buttons.push_back(Quit);
  FattigJohan_Button FattigJohan{200,200,280,260,6};
  Kresper_Button Kresper{200,200,480,260,7};
  Krallex_Button Krallex{200,200,680,260,8};
  Kraxel_Button Kraxel{200,200,880,260,9};
  choose_char1_buttons.push_back(FattigJohan);
  choose_char1_buttons.push_back(Kresper);
  choose_char1_buttons.push_back(Krallex);
  choose_char1_buttons.push_back(Kraxel);


  while(state != "quit" && state != "match" && running == true)
  {
    clock.restart();
    if(state == "main")
    {
      running = main_loop(clock,window,handler,event);
    }
    else if(state == "char1")
    {
      /*
      FattigJohan_Button Play{200,200,280,260,0};
      Kresper_Button Instructions{200,200,480,260,1};
      Krallex_Button Quit{200,200,680,260,2};
      Kraxel_Button Quit{200,200,880,260,2};
      char1 = choose_char1_loop(clock,window,handler,event);
      */
      choose_char1_loop(clock,window,handler,event);
    }
    /*
    else if(state == "char2")
    {
      choose_char2_loop(clock,window,handler,event);
    }
    else if(state == "playingfield")
    {
      choose_playingfield_loop(clock,window,handler,event);
    }*/
    else if(state == "instructions")
    {
      std::cout << "i instructions";
      break;
      //show_instructions_loop(clock,window,handler,event);
    }
    auto frameDelay = clock.getElapsedTime();
    if ( targetFrameDelay > frameDelay )
    {
        // only wait if it is actually needed
        auto sleepTime = targetFrameDelay - frameDelay;
        sf::sleep(sleepTime);
    }
  }
  if(state == "quit")
  {
    std::cout << "i quit";
  }
}

bool Menu::main_loop(sf::Clock & clock,sf::RenderWindow & window, Menu_Texture_handler & table,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = main_buttons.begin() ; it != main_buttons.end(); ++it)
  {
    if(!(mouse.x > it->get_limits().right || mouse.x < it->get_limits().left ||
      mouse.y > it->get_limits().lower || mouse.y < it->get_limits().upper))
      {
        //std::cout << "attans?";
        sf::Sprite sprite{};
        sprite.setTexture(table.get_texture(it->get_texture_index()));
        sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
        window.draw(sprite);
          if ( event.type == sf::Event::MouseButtonPressed )
            {
              if(event.mouseButton.button == sf::Mouse::Button::Left)
              {
                if (event.type == sf::Event::Closed)
                  {
                    return false;
                  }
                state = it->get_state();
                //std::cout << "Hallå?";
              }

            }
        }
    else
    {
      if (event.type == sf::Event::Closed)
        {
          return false;
        }
      sf::Sprite sprite{};
      sprite.setTexture(table.get_texture(it->get_texture_index()));
      sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
      window.draw(sprite);
    }
  }
  }
  window.display();
  return true;
  //Kolla om knapp intryckt
}

void Menu::choose_char1_loop(sf::Clock & clock,sf::RenderWindow & window, Menu_Texture_handler & table,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  for(std::vector<Menu_Button>::iterator it = choose_char1_buttons.begin() ; it != choose_char1_buttons.end(); ++it)
  {
    if(!(mouse.x > it->get_limits().right || mouse.x < it->get_limits().left ||
      mouse.y > it->get_limits().lower || mouse.y < it->get_limits().upper))
      {
        sf::Sprite sprite{};
        sprite.setTexture(table.get_texture(it->get_texture_index() + 3));
        sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
        window.draw(sprite);
        while(window.pollEvent(event))
        {
          if ( event.type == sf::Event::MouseButtonPressed )
          {
            if(event.mouseButton.button == sf::Mouse::Button::Left)
            {
              state = "char2";
              //return it->get_state();
            }
          }
        }
      }
    else
    {
      sf::Sprite sprite{};
      sprite.setTexture(table.get_texture(it->get_texture_index()));
      sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
      window.draw(sprite);
    }
  }
  window.display();
}
