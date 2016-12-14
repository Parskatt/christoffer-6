//
//Attack.cc
//

#include "Attack.h"


//
//Attack
//
Attack::Attack(int width,int height,int x,int y,std::initializer_list<std::string> il,int direction)
    :Object{width,height,x,y,il},direction{direction},done_counter{0}
{}

void Attack::render(sf::RenderWindow & window)
{
  sf::Sprite sprite{};
  sprite.setTexture(texture_handler.get_texture(floor(done_counter/5)));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
  if (done_counter < 10*5)
  {
  done_counter += 1;
  }
}

bool Attack::done()
{
  if(done_counter > 9*5)
  {
    return true;
  }
  return false;
}
void Attack::set_xpos(int xpos)
{
  position.xpos = xpos;
}
void Attack::set_ypos(int ypos)
{
  position.ypos = ypos;
}

//---------------------------------------------------------------------
//
//Punch
//

Punch::Punch(int width,int height,int x,int y,std::initializer_list<std::string> il,int direction,std::vector<Projectile> & projectiles)
    :Attack{width,height,x,y,il,direction}
{
  projectiles.push_back(Punch_projectile{20,20,x,y+50,5,direction,30});
}
