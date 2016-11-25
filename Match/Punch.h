#ifndef PUNCH_H
#define PUNCH_H

#include "Attack.h"
#include "Match.h"
#include <SFML/Graphics.hpp>

class Punch
{
private:
    
public:
    Punch{int width ,int height,int x,int y,int direction,Match match};
    int get_texture_index() override;
}
