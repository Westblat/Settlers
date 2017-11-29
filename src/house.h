#ifndef HOUSE_H
#define HOUSE_H
#include "building.h"
#include "terrain.h"

class House: public Building {
public:
    House(int health, int space, Terrain *terrain); //space as in inventory space
    void build();
private:
    int space;
    Terrain *terrain;
};

#endif