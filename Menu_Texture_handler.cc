//
//Texture_handler.cc
//

#include "Menu_Texture_handler.h"
#include <iostream>

Menu_Texture_handler::Menu_Texture_handler()
  :textures{33} //number of textures
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
    if (!textures[10].loadFromFile("Bilder/svart.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    /*if (!textures[11].loadFromFile("Bilder/Instructionsloop.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[12].loadFromFile("Bilder/Instructionstext.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }*/
    //John Cena nedan
    if (!textures[11].loadFromFile("Bilder/1.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[12].loadFromFile("Bilder/2.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[13].loadFromFile("Bilder/3.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[14].loadFromFile("Bilder/4.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[15].loadFromFile("Bilder/5.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[16].loadFromFile("Bilder/6.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[17].loadFromFile("Bilder/7.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[18].loadFromFile("Bilder/8.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[19].loadFromFile("Bilder/9.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[20].loadFromFile("Bilder/10.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[21].loadFromFile("Bilder/11.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[22].loadFromFile("Bilder/12.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[23].loadFromFile("Bilder/13.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[24].loadFromFile("Bilder/14.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[25].loadFromFile("Bilder/15.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[26].loadFromFile("Bilder/16.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[27].loadFromFile("Bilder/17.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[28].loadFromFile("Bilder/18.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[29].loadFromFile("Bilder/19.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[30].loadFromFile("Bilder/20.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[31].loadFromFile("Bilder/21.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    if (!textures[32].loadFromFile("Bilder/22.png"))
    {
      throw 1; //Gör en exceptionklass för texture_handler som ärver från std::logic_error
    }
    //Slut på Cena

}

sf::Texture const & Menu_Texture_handler::get_texture(int index) const
{
  return textures[index];
}
