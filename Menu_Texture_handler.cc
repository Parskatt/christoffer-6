//
//Texture_handler.cc
//

#include "Menu_Texture_handler.h"
#include <iostream>

Menu_Texture_handler::Menu_Texture_handler()
  :textures{1} //number of textures
{
    if (!textures[0].loadFromFile("Bilder/Play.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }

}

sf::Texture const & Menu_Texture_handler::get_texture(int index) const
{
  return textures[index];
}
