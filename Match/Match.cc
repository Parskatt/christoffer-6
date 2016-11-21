/*
*Match.cc
*/

#include "Match.h"
Match::Match(int char1,int char2,int playfield)
  :playing_field{playfield}
{
  (void)char1;
  (void)char2;
}
void Match::graphic_update()
{
      clock.restart();
      window.clear();

      // Draw things
      /*
      for (std::vector<Movable>::iterator it = movable_objects.begin() ; it != moveable_objects.end(); ++it)
        {
          window.draw(*it.get_sprite());
        }
      for (std::vector<Object>::iterator it = nonmovable_objects.begin() ; it != nonmoveable_objects.end(); ++it)
        {
          window.draw(*it.get_sprite());
        }
        */
      window.draw(playing_field.get_sprite());

      // show the newly drawn things
      window.display();
}
void Match::match_loop()
{
      sf::Clock clock;
      sf::Time targetFrameDelay {sf::milliseconds(10)};
      while(match)
      {
        //keyboard_handler();
        //position_update();
        graphic_update();
        auto frameDelay = clock.getElapsedTime();
        if ( targetFrameDelay > frameDelay )
        {
            // only wait if it is actually needed
            auto sleepTime = targetFrameDelay - frameDelay;
            sf::sleep(sleepTime);
        }
        if (dead_check)
        {
          match = false;
        }
      }
}
/*
void keyboard_handler();

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
