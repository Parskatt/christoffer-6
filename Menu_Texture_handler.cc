//
//Texture_handler.cc
//

#include "Menu_Texture_handler.h"
#include <iostream>

Menu_Texture_handler::Menu_Texture_handler()
  :textures{6} //number of textures
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
    if (!textures[3].loadFromFile("Bilder/Play2.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[4].loadFromFile("Bilder/Instructions2.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[5].loadFromFile("Bilder/Quit2.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[6].loadFromFile("Bilder/FattigJohan.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }

    if (!textures[7].loadFromFile("Bilder/Kresper.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[8].loadFromFile("Bilder/Krallex.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[9].loadFromFile("Bilder/Kraxel.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }


}

sf::Texture const & Menu_Texture_handler::get_texture(int index) const
{
  return textures[index];
}
