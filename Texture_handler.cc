//
//Texture_handler.cc
//

#include "Texture_handler.h"

Texture_handler::Texture_handler()
  :textures{3} //number of textures
{
    if (!textures[0].loadFromFile("Bilder/background.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[1].loadFromFile("Bilder/platform.png"))
    {
      throw 1;
    }
    if (!textures[2].loadFromFile("Bilder/kraxlig.png"))
    {
      throw 1;
    }

}

sf::Texture const & Texture_handler::get_texture(int index) const
{
  return textures[index];
}
