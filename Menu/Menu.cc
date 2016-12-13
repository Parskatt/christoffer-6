#include "Menu.h"




Menu::Menu()
:state{"main"},main_buttons{}, choose_char1_buttons{}, choose_char2_buttons{}, choose_playingfield_buttons{}, show_instructions_buttons{}
,show_character_texts{}
{}





void Menu::menu_loop(bool & running)
{
  sf::Music music;
  if (!music.openFromFile("Menu/BackgroundMusic.wav"))
    {
      std::cout << "attans grabbar!";
    } // error
  music.play();

  //Menu_Texture_handler handler{};
  //bool running{true};
  sf::Event event;
  sf::Clock clock;
  sf::Time targetFrameDelay {sf::milliseconds(10)};
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window{sf::VideoMode{1280,720},"SFML Test", sf::Style::Default, settings};
  //Mainknappar
  Play_Button Play{320,100,480,210,{"Bilder/Menu/Play.png","Bilder/Menu/Play2.png"}};
  Instructions_Button Instructions{320,100,480,310,{"Bilder/Menu/Instructions.png","Bilder/Menu/Instructions2.png"}};
  Quit_Button Quit{320,100,480,410,{"Bilder/Menu/Quit.png","Bilder/Menu/Quit2.png"}};
  main_buttons.push_back(Play);
  main_buttons.push_back(Instructions);
  main_buttons.push_back(Quit);
  //Choose character knappar
  FattigJohan_Button FattigJohan{200,200,280,260,{"Bilder/Menu/FattigJohan.png"}};
  Kresper_Button Kresper{200,200,480,260,{"Bilder/Menu/Kresper.png"}};
  Krallex_Button Krallex{200,200,680,260,{"Bilder/Menu/Krallex.png"}};
  Kraxel_Button Kraxel{200,200,880,260,{"Bilder/Menu/Kraxel.png"}};
  choose_char1_buttons.push_back(FattigJohan);
  choose_char1_buttons.push_back(Kresper);
  choose_char1_buttons.push_back(Krallex);
  choose_char1_buttons.push_back(Kraxel);
  choose_char2_buttons.push_back(FattigJohan);
  choose_char2_buttons.push_back(Kresper);
  choose_char2_buttons.push_back(Krallex);
  choose_char2_buttons.push_back(Kraxel);
  //Instructionsknappar
  Instructionsloop_Button Back{280,720,0,0,{"Bilder/Menu/Back.png"}};
  show_instructions_buttons.push_back(Back);
  //Playingfieldknappar
  Playingfield_Button Playingfield{1280,720,0,0,{"Bilder/Menu/Playingfield.png"}};
  choose_playingfield_buttons.push_back(Playingfield);

  //Text för olika grejer
  Menu_Text FattigJohantext{200,200,280,175,{"Bilder/Menu/FattigJohantext.png"}};
  Menu_Text Krespertext{200,200,480,175,{"Bilder/Menu/Krespertext.png"}};
  Menu_Text Krallextext{200,200,680,175,{"Bilder/Menu/Krallextext.png"}};
  Menu_Text Kraxeltext{200,200,880,175,{"Bilder/Menu/Kraxeltext.png"}};
  show_character_texts.push_back(FattigJohantext);
  show_character_texts.push_back(Krespertext);
  show_character_texts.push_back(Kraxeltext);
  show_character_texts.push_back(Krallextext);
  Menu_Text Instructionstext{200,200,280,0,{"Bilder/Menu/Instructionstext.png"}};
  show_instructions_text = Instructionstext;
  while(state != "quit" && state != "match" && running == true)
  {
    clock.restart();
    if(state == "main")
    {
      running = main_loop(clock,window,event);
      if (state == "char1" || state == "instructions")
      {
        window.clear();
      }
    }
    else if(state == "char1")
    {
      running = choose_char1_loop(clock,window,event);
      if(state == "char2")
      {
        if(char1 == "Krallex")
        {
          krallex_pick(window,event);
        }
        window.clear();
      }
    }
    else if(state == "char2")
    {
      running = choose_char2_loop(clock,window,event);
      if(state == "playingfield")
      {
        if(char2 == "Krallex")
        {
          krallex_pick(window,event);
        }
        window.clear();
      }
    }
    else if(state == "playingfield")
    {
      choose_playingfield_loop(clock,window,event);
      if(state == "match")
      {
        std::cout << "i match" << std::endl;
      }
    }
    else if(state == "instructions")
    {
      running = show_instructions_loop(clock,window,event);
      if(state == "main")
      {
        window.clear();
      }
    }
    auto frameDelay = clock.getElapsedTime();
    if ( targetFrameDelay > frameDelay )
    {
        auto sleepTime = targetFrameDelay - frameDelay;
        sf::sleep(sleepTime);
    }
  }
  if(state == "quit")
  {
    running = false;
  }
  }

bool Menu::main_loop(sf::Clock & clock,sf::RenderWindow & window,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
    for(std::vector<Menu_Button>::iterator it = main_buttons.begin() ; it != main_buttons.end(); ++it)
    {
      if(it->inside_button(mouse.x,mouse.y))
        {
          it->render(window,1);
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
        it->render(window);
      }
    }
  }
  window.display();
  return true;
  //Kolla om knapp intryckt
}

bool Menu::choose_char1_loop(sf::Clock & clock,sf::RenderWindow & window,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = choose_char1_buttons.begin() ; it != choose_char1_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        it->render(window);
          if ( event.type == sf::Event::MouseButtonPressed )
          {
            if(event.mouseButton.button == sf::Mouse::Button::Left)
            {
              char1 = it->get_state();
              state = "char2";
            }
          }
        }
    else
    {
      if (event.type == sf::Event::Closed)
        {
          return false;
        }
      it->render(window);
    }
  }
}
  for(std::vector<Menu_Text>::iterator it = show_character_texts.begin() ; it != show_character_texts.end(); ++it)
  {
    it->render(window);
  }
  window.display();
  return true;
}

bool Menu::choose_char2_loop(sf::Clock & clock,sf::RenderWindow & window,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = choose_char1_buttons.begin() ; it != choose_char1_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        it->render(window);
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
      it->render(window);
    }
  }
}

for(std::vector<Menu_Text>::iterator it = show_character_texts.begin() ; it != show_character_texts.end(); ++it)
{
  it->render(window);
}
  window.display();
  return true;
}

bool Menu::show_instructions_loop(sf::Clock & clock, sf::RenderWindow & window, sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = show_instructions_buttons.begin() ; it != show_instructions_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        it->render(window);
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
      it->render(window);
    }
  }
}

  show_instructions_text.render(window);
  window.display();
  return true;
}

bool Menu::choose_playingfield_loop(sf::Clock & clock,sf::RenderWindow & window,sf::Event & event)
{
  auto mouse = sf::Mouse::getPosition(window);
  //Grafik
  while(window.pollEvent(event))
  {
  for(std::vector<Menu_Button>::iterator it = choose_playingfield_buttons.begin() ; it != choose_playingfield_buttons.end(); ++it)
  {
    if(it->inside_button(mouse.x,mouse.y))
      {
        it->render(window);
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
      it->render(window);
    }
  }
}
  window.display();
  return true;
}

void Menu::krallex_pick(sf::RenderWindow & window, sf::Event & event)
{
  window.clear();
  sf::SoundBuffer buffer;
  buffer.loadFromFile("Menu/JohnCena.wav");
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
  std::vector<sf::Texture> cenatextures{23};
  for(int it{1}; it < 23; ++it)
  {
    std::stringstream string{};
    string << "Bilder/Menu/Cena/" << it << ".png";
    cenatextures[it].loadFromFile(string.str());
  }

  for (int i {0}; i < 8; ++i)
  {
      for(int it{1}; it < 23; ++it)
      {

        //std::cout << "hallå";
        sf::Sprite sprite{};
        sprite.setTexture(cenatextures[it]);
        sprite.setPosition(sf::Vector2f(450,250));
        window.draw(sprite);
        window.display();
        sf::sleep(sf::milliseconds(50));
      }
  }
}

int Menu::get_char1()
{
  if (char1=="FattigJohan")
   {
     return 1;
   }
  else if (char1 == "Kresper")
  {
    return 2;
  }
  else if (char1 == "Krallex")
  {
    return 1;
  }
  else
  {
    return 1;
  }
}

int Menu::get_char2()
{
  if (char2=="FattigJohan")
   {
     return 1;
   }
  else if (char2 == "Kresper")
  {
    return 2;
  }
  else if (char2 == "Krallex")
  {
    return 1;
  }
  else
  {
    return 1;
  }
}

int Menu::get_playingfield()
{

  return 1;
}
