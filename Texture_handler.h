//
//Texture_handler.h
//

#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H


#include <SFML/Graphics.hpp>

class Texture_handler
{
  public:
    Texture_handler();

    ~Texture_handler() = default;

    sf::Texture const & get_texture(int) const;

    std::vector<sf::Texture> textures{};
};

#endif
