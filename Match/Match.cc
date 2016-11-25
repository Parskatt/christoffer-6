/*
*Match.cc
*/

#include "Match.h"
#include <iostream>


Match::Match(int char1,int char2,int playfield)
  :playing_field{1280,720,0,0,playfield}
{
  nonmovable_objects.push_back(playing_field);
  nonmovable_objects.push_back(playing_field.get_platform());//Platform{1280,200,0,500,1});
  (void)char1;
  (void)char2;
}

void Match::run()
{
    Texture_handler handler{};
    bool running{true};
    sf::Event event;
    sf::Clock clock;
    sf::Time targetFrameDelay {sf::milliseconds(10)};
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window{sf::VideoMode{1280,720},"SFML Test", sf::Style::Default, settings};
    while(running)
    {
      keyboard_handler(window);
      //position_update();
      graphic_update(clock,window,handler);
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
}

void Match::graphic_update(sf::Clock & clock,sf::RenderWindow & window,Texture_handler & table)
{
      clock.restart();
      window.clear();

      // Draw things
      for (std::vector<Object>::iterator it = nonmovable_objects.begin() ; it != nonmovable_objects.end(); ++it)
        {
           sf::Sprite sprite{};
      	   sprite.setTexture(table.get_texture(it->get_texture_index()));
      	   sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
      	   window.draw(sprite);
        }

      // show the newly drawn things
      window.display();
}


void Match::keyboard_handler(sf::RenderWindow & window)
{

  while(window.pollEvent(event))
  {
    int i{};
    for(std::vector<sf::Keyboard>::iterator it{p1_commands.begin()}; it != p1_commands.end(); ++it)
    {
      if(event.key.code == *it)
      {
        player1.send_key(i)
      }
      ++i;
    }

    int y{};
    for(std::vector<sf::Keyboard>::iterator it{p2_commands.begin()}; it != p2_commands.end(); ++it)
    {
      if(event.key.code == *it)
      {
        player2.send_key(y)
      }
      ++y;
    }
  }
/*
    if(event.key.code == sf::Keyboard::Left)
    {
      player1.send_key(1);
    }
    else if(event.key.code == sf::Keyboard::Right)
    {
      player1.send_key(2);
    }
    else if(event.key.code == sf::Keyboard::Up)
    {
      player1.send_key(3);
    }
    else if(event.key.code == sf::Keyboard::Down)
    {
      player1.send_key(4);
    }
    else if(event.key.code == sf::Keyboard::Space)
    {
      player1.send_key(5);
    }*/

}

/*
void position_update(Object object)
{
  object.move();
}

void collision_update(Object object)
{
  for (std::vector<Movable>::iterator it = movable_objects.begin() ; it != moveable_objects.end(); ++it)
      {
        if(physics_engine.collision(object, *it))
        //if(((object.get_limits().right < *it.get_limits().left)
        //|| (object.get_limits().lower < *it.get_limits().upper))
        {
          std::cout << "attans!";
        }
      }
}


void position_update()
{
  physics_engine.gravity();
  for (std::vector<Movable>::iterator it = movable_objects.begin() ; it != moveable_objects.end(); ++it)
    {
      position_update(*it);
    }
  for (std::vector<Movable>::iterator it = movable_objects.begin() ; it != moveable_objects.end(); ++it)
      {
        //collision_update(*it);
      }
  for (std::vector<Object>::iterator it = nonmovable_objects.begin() ; it != nonmoveable_objects.end(); ++it)
      {
        //collision_update(*it);
      }

}

bool dead_check()
{
  return false;
}
*/
