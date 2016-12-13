//
//Projectile.cc

#include "Projectile.h"

Projectile::Projectile(int width,int height,int x,int y,std::initializer_list<std::string> il,int speed,int direction,int damage,int range)
    :Movable{width,height,x,y,il,speed,direction,0}, damage{damage}, done_counter{0}, range{range}
{

}


void Projectile::move()
{
  position.xpos += direction * speed;
  update_limits();
}



int Projectile::get_damage() const
{
  return damage;
}

void Projectile::render(sf::RenderWindow & window)
{
  sf::Sprite sprite{};
  sprite.setTexture(texture_handler.get_texture(0));
  sprite.setPosition(sf::Vector2f(position.xpos,position.ypos));
  window.draw(sprite);
  if (done_counter < range)
  {
    done_counter += 1;
  }
}

bool Projectile::done()
{
  if(done_counter >= range)
  {
    return true;
  }
  return false;
}

int Projectile::get_range()
{
  return range;
}



//-----------------------------------------------------------------------------

Punch_projectile::Punch_projectile(int width,int height,int x,int y,std::initializer_list<std::string> il,int speed,int direction,int damage)
    :Projectile{width,height,x,y,il,speed,direction,damage,25}
{

}
