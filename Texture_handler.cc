//
//Texture_handler.cc
//

#include "Texture_handler.h"

Texture_handler::Texture_handler(std::initializer_list<std::string> il)
  :textures{il.size()} //number of textures
{

    int i{0};
    for(std::string path : il)
    {
      if (!textures[i].loadFromFile(path))
      {
        throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
      }
      ++i;
    }
}

sf::Texture const & Texture_handler::get_texture(int index) const
{
  return textures[index];
}
