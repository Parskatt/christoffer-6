//
//Texture_handler.cc
//

#include "Texture_handler.h"

Texture_handler::Texture_handler()
  :textures{5} //number of textures
{
    if (!textures[1].loadFromFile("Bilder/background1.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    /*else if (!textures[1].loadFromFile("Bilder/platform.png"))
    {
      throw 1;
    }*/
    else if (!textures[2].loadFromFile("Bilder/cammy.png"))
    {
      throw 1;
    }
    else if(!textures[3].loadFromFile("Bilder/healthbar.png"))
    {
      throw 1;
    }
    else if(!textures[4].loadFromFile("Bilder/cammy1.png"))
    {
      throw 1;
    }

}

sf::Texture const & Texture_handler::get_texture(int index) const
{
  return textures[index];
}
