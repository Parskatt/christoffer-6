//
//Attack.cc
//

#include "Attack.h"
//#include time

Attack::Attack(int width,int height,int x,int y,int index,int direction)
    :Object{width,height,x,y,index},direction{direction}
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
  sprite.setTexture(table.get_texture(texture_index));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
}



Punch::Punch(int width,int height,int x,int y,int index,int direction,std::vector<Projectile> & projectiles)
    :Attack{width,height,x,y,index,direction}
{
  projectiles.push_back(Punch_projectile{20,20,x,y,index,10,direction,50});
}
