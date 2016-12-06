/*
*Match.cc
*/

#include "Match.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <iostream>

Match::Match(int char1,int char2,int playfield)
  :/*movable_objects{}, nonmovable_objects{},*/ playing_field{1280,720,0,0,playfield},
   player1{char1,1},player2{char2,2},p1_commands{4},p2_commands{4}//---------------------------------------------------
{
  
  //auto it = nonmovable_objects.begin();
  //it = nonmovable_objects.insert(it,&playing_field);
  //nonmovable_objects.push_back(playing_field.get_platform());
  //movable_objects.push_back(std::make_unique<Character>(player1.get_curr_character()));
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

/*Match::~Match()
{
  for (std::vector<Object*>::iterator it = nonmovable_objects.begin() ; it != nonmovable_objects.end(); ++it)
  {
    delete (*it);
  }
  for (std::vector<Object*>::iterator it = nonmovable_objects.begin() ; it != nonmovable_objects.end(); ++it)
  {
    delete (*it);
  }
}*/

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
    window.setVerticalSyncEnabled(true);

    while(running)
    {
      clock.restart();
      keyboard_handler(window,event,running);
      position_update();
      graphic_update(clock,window,handler);
      auto frameDelay = clock.getElapsedTime();
      if ( targetFrameDelay > frameDelay )
      {
          // only wait if it is actually needed
          auto sleepTime = targetFrameDelay - frameDelay;
          sf::sleep(sleepTime);
      }
    }
}

void Match::graphic_update(sf::Clock & clock,sf::RenderWindow & window,Texture_handler & table)
{
      clock.restart();
      window.clear();

      playing_field.render(window,table);
      player1.render(window,table);
      player2.render(window,table);

      /*// Draw things
      for (std::vector<std::unique_ptr<Object>>::iterator it = nonmovable_objects.begin() ; it != nonmovable_objects.end(); ++it)//Innehåller inte object alla movables också?
        {

          (*it)->render(window,table);
          //std::cout << "1" << std::endl;
           //sf::Sprite sprite{};
      	   //sprite.setTexture(table.get_texture(it->get_texture_index()));
      	   //sprite.setPosition(sf::Vector2f(it->get_position().xpos,it->get_position().ypos));
      	   //window.draw(sprite);
        }
      for (std::vector<std::unique_ptr<Movable>>::iterator it = movable_objects.begin() ; it != movable_objects.end(); ++it) //-----------------------------------------------------------------------
        {
          (*it)->render(window,table);
           //sf::Sprite sprite{};
           //sprite.setTexture(table.get_texture((*it)->get_texture_index()));
           //sprite.setPosition(sf::Vector2f((*it)->get_position().xpos,(*it)->get_position().ypos));
           //window.draw(sprite);
        }*/

      // show the newly drawn things
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
/*
    if(event.type == sf::Event::KeyPressed)
    {
      if(event.key.code == sf::Keyboard::Left)
      {
        player1.send_key(0);
      }
      else if(event.key.code == sf::Keyboard::Right)
      {
        player1.send_key(1);
      }
      else if(event.key.code == sf::Keyboard::Up)
      {
        player1.send_key(2);
      }
    if(event.type == sf::Event::KeyReleased)
    {
      std::cout << "släppteknapp" << std::endl;
      player1.send_key(3);
    }
  }
}*/

}


/*void Match::position_update(std::unique_ptr<Movable> & object) //-----------------------------------------------------------------------------------
{
  object->move();
}*/

void Match::position_update()
{
  player1.position_update();
  player2.position_update();

  //physics_engine.gravity();
  //for (std::vector<std::unique_ptr<Movable>>::iterator it = movable_objects.begin() ; it != movable_objects.end(); ++it) //-------------------------------------------------------------------------------
  //  {
  //    position_update(*it);
  //    //collision_update(*it);
  //  }

    /*
  for (std::vector<Object>::iterator it = nonmovable_objects.begin() ; it != nonmoveable_objects.end(); ++it)
      {
        //collision_update(*it);
      }*/

}


/*
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

*/


/*
bool dead_check()
{
  return false;
}
*/
