//
//Attack.cc
//

#include "Attack.h"
//#include time

Attack::Attack(int width,int height,int x,int y,int index,int direction)
    :Object{width,height,x,y,index}
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



Punch::Punch(int width,int height,int x,int y,int index,int direction)
    :Attack{width,height,x,y,index,direction}
{
 //curr_projectile = Punch_projectile{20,20,?,?,nåt index,direction,damage};

}
