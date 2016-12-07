//
//Projectile.cc

#include "Projectile.h"

Projectile::Projectile(int width,int height,int x,int y,std::initializer_list<std::string> il,int speed,int direction,int damage)
    :Movable{width,height,x,y,il,speed,direction,0}, damage{damage}
{

}


void Projectile::move()
{
  position.xpos += direction * speed;
}

int Projectile::get_damage() const
{
  return damage;
}

//-----------------------------------------------------------------------------

Punch_projectile::Punch_projectile(int width,int height,int x,int y,std::initializer_list<std::string> il,int speed,int direction,int damage)
    :Projectile{width,height,x,y,il,speed,direction,damage}
{

}

int Punch_projectile::get_range()
{
  return range;
}

void Projectile::render(sf::RenderWindow & window)
{
  sf::Sprite sprite{};
  sprite.setTexture(texture_handler.get_texture(0));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
}
