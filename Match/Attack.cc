//
//Attack.cc
//

#include "Attack.h"
//#include time

Attack::Attack(int width,int height,int x,int y,int index,int direction)
    :Object{width,height,x,y,index},direction{direction},done_counter{0},render_counter{0}
{
}

/*void Attack::wait()
{
  sleep(1);
  delete curr_projectile;
}*/

void Attack::render(sf::RenderWindow & window, Texture_handler & table)
{
  sf::Sprite sprite{};
  sprite.setTexture(table.get_texture(texture_index + render_counter));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
  render_counter += 1;
  if (render_counter > 3)
  {
    render_counter = 0;
  }
}
bool Attack::done()
{
  if(done_counter > 100)
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

Punch::Punch(int width,int height,int x,int y,int index,int direction,std::vector<Projectile> & projectiles)
    :Attack{width,height,x,y,index,direction}
{
  projectiles.push_back(Punch_projectile{20,20,x,y,index,10,direction,50});
}
