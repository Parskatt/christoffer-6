/*
*Match.cc
*/

#include "Match.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <iostream>


Match::Match(int char1,int char2,int playing_field)
  :playing_field{1280,720,0,0,playing_field},
   player1{1,char1},player2{2,char2},p1_commands{4},p2_commands{4}
{

  //Initialize commands, order is important
  p1_commands[0] = sf::Keyboard::Left;
  p1_commands[1] = sf::Keyboard::Right;
  p1_commands[2] = sf::Keyboard::Up; //Hoppa
  p1_commands[3] = sf::Keyboard::M; //Attack

  p2_commands[0] = sf::Keyboard::A;
  p2_commands[1] = sf::Keyboard::D;
  p2_commands[2] = sf::Keyboard::W; //Hoppa
  p2_commands[3] = sf::Keyboard::Space; //Attack
}

void Match::run(bool & running)
{
    //Texture_handler handler{};
    bool match_running{true};
    sf::Event event;
    sf::Clock clock;
    sf::Time targetFrameDelay {sf::milliseconds(10)};
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window{sf::VideoMode{1280,720},"Gatukämpe 6 - Return of the Streetfighter?!", sf::Style::Default, settings};
    window.setVerticalSyncEnabled(true);
    Physics_engine engine{};

    while(running && match_running)
    {
      clock.restart();
      keyboard_handler(window,event,running);
      is_dead(match_running,window);
      position_update(engine,running);
      graphic_update(clock,window);
      auto frameDelay = clock.getElapsedTime();
      if ( targetFrameDelay > frameDelay )
      {
          // only wait if it is actually needed
          auto sleepTime = targetFrameDelay - frameDelay;
          sf::sleep(sleepTime);
      }
    }
}

void Match::graphic_update(sf::Clock & clock,sf::RenderWindow & window)
{
      clock.restart();
      //window.clear();

      playing_field.render(window);
      player1.render(window);
      player2.render(window);

      window.display();
}


void Match::keyboard_handler(sf::RenderWindow & window, sf::Event & event, bool & running)
{
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        running = false;
      }
    }
    //Alternativet till isKeyPressed vore att kolla KeyReleased, men fick det inte att funka vid första försöket,
    //men kanske vore bättre
    int i{0};
    for(std::vector<sf::Keyboard::Key>::iterator it{p1_commands.begin()}; it != p1_commands.end(); ++it)
    {
      if (sf::Keyboard::isKeyPressed(*it))
      {
        player1.send_key(i);
      }
      ++i;
    }

    int y{};
    for(std::vector<sf::Keyboard::Key>::iterator it{p2_commands.begin()}; it != p2_commands.end(); ++it)
    {
      if(sf::Keyboard::isKeyPressed(*it))
      {
        player2.send_key(y);
      }
      ++y;
    }

}

void Match::position_update(Physics_engine & engine, bool & running)
{
  engine.gravity(player1, player2);

  player1.position_update();
  player2.position_update();

  engine.collision(playing_field, player1, player2);
}

void Match::is_dead(bool & match_running, sf::RenderWindow & window)
{
  if (player1.get_curr_character().get_health() <= 0)
  {
    sf::Font font;
    font.loadFromFile("Bilder/DaStreets.ttf");
    sf::Text text("Player 1 got demolished :'('",font);
    text.setCharacterSize(70);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(sf::Vector2f(250,200));

    window.draw(text);
    window.display();

    sf::sleep(sf::seconds(7));

    match_running = false;
  }
  else if (player2.get_curr_character().get_health() <= 0)
  {
    sf::Font font;
    font.loadFromFile("Bilder/DaStreets.ttf");
    sf::Text text("Player 2 got demolished :/",font);
    text.setCharacterSize(70);
    text.setColor(sf::Color(0,0,0));
    text.setPosition(sf::Vector2f(250,200));

    window.draw(text);
    window.display();

    sf::sleep(sf::seconds(7));

    match_running = false;
  }
}
