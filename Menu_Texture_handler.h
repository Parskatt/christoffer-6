#ifndef MENU_TEXTURE_HANDLER_H
#define MENU_TEXTURE_HANDLER_H


#include <SFML/Graphics.hpp>

class Menu_Texture_handler
{
  public:
    Menu_Texture_handler();

    ~Menu_Texture_handler() = default;

    sf::Texture const & get_texture(int) const;

    std::vector<sf::Texture> textures{};
};

#endif
