#ifndef GAME_H
#define GAME_H

#include "map.h"

class Game
{
public:
    Game();
    ~Game();
    Map& getMap();
private:
    Map *map;
};

#endif // GAME_H
