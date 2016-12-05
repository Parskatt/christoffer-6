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
  sf::Time targetFrameDelay {sf::milliseconds(10)};
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window{sf::VideoMode{1280,720},"SFML Test", sf::Style::Default, settings};
  //Mainknappar
  Play_Button Play{320,100,480,210,0};
  Instructions_Button Instructions{320,100,480,310,1};
  Quit_Button Quit{320,100,480,410,2};
  main_buttons.push_back(Play);
  main_buttons.push_back(Instructions);
  main_buttons.push_back(Quit);
  //Choose character knappar
  FattigJohan_Button FattigJohan{200,200,280,260,6};
  Kresper_Button Kresper{200,200,480,260,7};
  Krallex_Button Krallex{200,200,680,260,8};
  Kraxel_Button Kraxel{200,200,880,260,9};
  choose_char1_buttons.push_back(FattigJohan);
  choose_char1_buttons.push_back(Kresper);
  choose_char1_buttons.push_back(Krallex);
  choose_char1_buttons.push_back(Kraxel);
  choose_char2_buttons.push_back(FattigJohan);
  choose_char2_buttons.push_back(Kresper);
  choose_char2_buttons.push_back(Krallex);
  choose_char2_buttons.push_back(Kraxel);
  //Instructionsknappar
  Instructionsloop_Button Back{280,720,0,0,37};
  show_instructions_buttons.push_back(Back);
  //Playingfieldknappar
  Playingfield_Button Playingfield{500,500,390,110,32};
  choose_playingfield_buttons.push_back(Playingfield);


  while(state != "quit" && state != "match" && running == true)
  {
    clock.restart();
    if(state == "main")
    {
      running = main_loop(clock,window,handler,event);
      if (state == "char1" || state == "instructions")
      {
        window.clear();
      }
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
      running = choose_char1_loop(clock,window,handler,event);
      if(state == "char2")
      {
        if(char1 == "Krallex")
        {
          krallex_pick(window,handler);
        }
        window.clear();
      }
    }
    else if(state == "char2")
    {
      running = choose_char2_loop(clock,window,handler,event);
      if(state == "playingfield")
      {
        if(char2 == "Krallex")
        {
          krallex_pick(window,handler);
        }
        window.clear();
      }
    }
    else if(state == "playingfield")
    {
      choose_playingfield_loop(clock,window,handler,event);
      if(state == "match")
      {
        std::cout << "wow";
      }
    }
    else if(state == "instructions")
    {
      running = show_instructions_loop(clock,window,handler,event);
      if(state == "main")
      {
        window.clear();
      }
    }
    auto frameDelay = clock.getElapsedTime();
    if ( targetFrameDelay > frameDelay )
    {
        // only wait if it is actually needed
        auto sleepTime = targetFrameDelay - frameDelay;
        sf::sleep(sleepTime);
    }
  }
  if(state == "quit"){}
  }

bool Menu::main_loop(sf::Clock & clock,sf::RenderWindow & window, Menu_Texture_handler & table,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
    for(std::vector<Menu_Button>::iterator it = main_buttons.begin() ; it != main_buttons.end(); ++it)
    {
      if(it->inside_button(mouse.x,mouse.y))
        {
          //std::cout << "attans?";
          sf::Sprite sprite{};
          sprite.setTexture(table.get_texture(it->get_texture_index() + 3));
          sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
          window.draw(sprite);
            if ( event.type == sf::Event::MouseButtonPressed )
              {
                if(event.mouseButton.button == sf::Mouse::Button::Left)
                {
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
        draw_sprite(it,window,table,0);
      }
    }
  }
  window.display();
  return true;
  //Kolla om knapp intryckt
}

bool Menu::choose_char1_loop(sf::Clock & clock,sf::RenderWindow & window, Menu_Texture_handler & table,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = choose_char1_buttons.begin() ; it != choose_char1_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        draw_sprite(it,window,table,0);;
          if ( event.type == sf::Event::MouseButtonPressed )
          {
            if(event.mouseButton.button == sf::Mouse::Button::Left)
            {
              char1 = it->get_state();
              state = "char2";
              //return it->get_state();
            }
          }
        }
    else
    {
      if (event.type == sf::Event::Closed)
        {
          return false;
        }
      draw_sprite(it,window,table,0);
    }
  }
}
  sf::Sprite FattigJohanText{};
  FattigJohanText.setTexture(table.get_texture(33));
  FattigJohanText.setPosition(sf::Vector2f(280,175));
  window.draw(FattigJohanText);

  sf::Sprite Krespertext{};
  Krespertext.setTexture(table.get_texture(34));
  Krespertext.setPosition(sf::Vector2f(480,175));
  window.draw(Krespertext);

  sf::Sprite Krallextext{};
  Krallextext.setTexture(table.get_texture(35));
  Krallextext.setPosition(sf::Vector2f(680,175));
  window.draw(Krallextext);

  sf::Sprite Kraxeltext{};
  Kraxeltext.setTexture(table.get_texture(36));
  Kraxeltext.setPosition(sf::Vector2f(880,175));
  window.draw(Kraxeltext);

  window.display();
  return true;
}

bool Menu::choose_char2_loop(sf::Clock & clock,sf::RenderWindow & window, Menu_Texture_handler & table,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = choose_char1_buttons.begin() ; it != choose_char1_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        draw_sprite(it,window,table,0);
          if ( event.type == sf::Event::MouseButtonPressed )
          {
            if(event.mouseButton.button == sf::Mouse::Button::Left)
            {
              char2 = it->get_state();
              state = "playingfield";
            }
          }
        }
    else
    {
      if (event.type == sf::Event::Closed)
        {
          return false;
        }
      draw_sprite(it,window,table,0);
    }
  }
}
sf::Sprite FattigJohanText{};
FattigJohanText.setTexture(table.get_texture(33));
FattigJohanText.setPosition(sf::Vector2f(280,175));
window.draw(FattigJohanText);

sf::Sprite Krespertext{};
Krespertext.setTexture(table.get_texture(34));
Krespertext.setPosition(sf::Vector2f(480,175));
window.draw(Krespertext);

sf::Sprite Krallextext{};
Krallextext.setTexture(table.get_texture(35));
Krallextext.setPosition(sf::Vector2f(680,175));
window.draw(Krallextext);

sf::Sprite Kraxeltext{};
Kraxeltext.setTexture(table.get_texture(36));
Kraxeltext.setPosition(sf::Vector2f(880,175));
window.draw(Kraxeltext);
  window.display();
  return true;
}

bool Menu::show_instructions_loop(sf::Clock & clock, sf::RenderWindow & window,Menu_Texture_handler & table, sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = show_instructions_buttons.begin() ; it != show_instructions_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        draw_sprite(it,window,table,0);
          if ( event.type == sf::Event::MouseButtonPressed )
          {
            if(event.mouseButton.button == sf::Mouse::Button::Left)
            {
              state = it->get_state();
            }
          }
        }
    else
    {
      if (event.type == sf::Event::Closed)
        {
          return false;
        }
      draw_sprite(it,window,table,0);
    }
  }
}
  sf::Sprite sprite{};
  sprite.setTexture(table.get_texture(38));
  sprite.setPosition(sf::Vector2f(280,0));
  window.draw(sprite);
  window.display();
  return true;
}

bool Menu::choose_playingfield_loop(sf::Clock & clock,sf::RenderWindow & window, Menu_Texture_handler & table,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = choose_playingfield_buttons.begin() ; it != choose_playingfield_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        draw_sprite(it,window,table,0);
          if ( event.type == sf::Event::MouseButtonPressed )
          {
            if(event.mouseButton.button == sf::Mouse::Button::Left)
            {
              playingfield = it->get_state();
              state = "match";
            }
          }
        }
    else
    {
      if (event.type == sf::Event::Closed)
        {
          return false;
        }
      draw_sprite(it,window,table,0);
    }
  }
}
  window.display();
  return true;
}
















void Menu::draw_sprite(std::vector<Menu_Button>::iterator & it,sf::RenderWindow & window, Menu_Texture_handler & table,int textplus)
{
  sf::Sprite sprite{};
  sprite.setTexture(table.get_texture(it->get_texture_index() + textplus));
  sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
  window.draw(sprite);
}

void Menu::krallex_pick(sf::RenderWindow & window, Menu_Texture_handler & handler)
{
  window.clear();
  sf::SoundBuffer buffer;
  buffer.loadFromFile("Menu/JohnCena.wav");
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
    for (int i {0}; i < 8; ++i)
    {
      for(int it{11}; it < 33; ++it)
      {
        //std::cout << "hallå";
        sf::Sprite sprite{};
        sprite.setTexture(handler.get_texture(it));
        sprite.setPosition(sf::Vector2f(450,250));
        window.draw(sprite);
        window.display();
        sf::sleep(sf::milliseconds(50));
      }
    }
}
