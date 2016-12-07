//
//Projectile.cc

#include "Projectile.h"

Projectile::Projectile(int width,int height,int x,int y,int index,int speed,int direction,int damage)
    :Movable{width,height,x,y,index,speed,direction,0}, damage{damage}
{

}


void Projectile::move()
{
  std::cout << direction << std::endl;
  position.xpos += direction * speed;
}

//-----------------------------------------------------------------------------

Punch_projectile::Punch_projectile(int width,int height,int x,int y,int index,int speed,int direction,int damage)
    :Projectile{width,height,x,y,index,speed,direction,damage}
{

}

int Punch_projectile::get_range()
{
  return range;
}

void Projectile::render(sf::RenderWindow & window, Texture_handler & table)
{
  sf::Sprite sprite{};
  sprite.setTexture(table.get_texture(texture_index));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
}
