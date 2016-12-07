//
//Attack.cc
//

#include "Attack.h"

//#include time


//
//Attack
//
Attack::Attack(int width,int height,int x,int y,std::initializer_list<std::string> il,int direction)
    :Object{width,height,x,y,il},direction{direction},done_counter{0},render_counter{10}
{
}

/*void Attack::wait()
{
  sleep(1);
  delete curr_projectile;
}*/

void Attack::render(sf::RenderWindow & window)
{
  sf::Sprite sprite{};
  sprite.setTexture(texture_handler.get_texture(0 + floor(render_counter/5)));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
  render_counter += 1;
  if (render_counter > 15)
  {
    render_counter = 0;
  }
}

bool Attack::done()
{
  if(done_counter > 15)
  {
    done_counter = 0;
    return true;
  }
  done_counter += 1;
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
  projectiles.push_back(Punch_projectile{20,20,x,y,{"Bilder/tom.png"},10,direction,50});
}
