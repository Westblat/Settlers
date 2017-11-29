#ifndef GAME_H
#define GAME_H
#include "map.h"
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
    void addSettler(House *house);
    std::vector<Settler*> getSettlers();
    std::vector<Building*> getBuildings();
private:
    Map *map;
    std::vector<Building*> buildings;
    std::vector<Settler*> settlers;
};

#endif // GAME_H
