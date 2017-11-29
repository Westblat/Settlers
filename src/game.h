#ifndef GAME_H
#define GAME_H
#include "map.h"
#include "settler.h"
#include "building.h"
#include "house.h"


class Game
{
public:
    Game();
    ~Game();
    Map& getMap();
    void setBuildings();
    void addBuilding(int type, Coordinates *location);
private:
    Map *map;
    std::vector<Building*> buildings;
};

#endif // GAME_H
