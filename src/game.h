#ifndef GAME_H
#define GAME_H
#include "map.h"
#include "settler.h"
#include "house.h"


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
