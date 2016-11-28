//
//Texture_handler.cc
//

#include "Menu_Texture_handler.h"
#include <iostream>

Menu_Texture_handler::Menu_Texture_handler()
  :textures{3} //number of textures
{
    if (!textures[0].loadFromFile("Bilder/Play.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[1].loadFromFile("Bilder/Instructions.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[2].loadFromFile("Bilder/Quit.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }

}

sf::Texture const & Menu_Texture_handler::get_texture(int index) const
{
  return textures[index];
}
