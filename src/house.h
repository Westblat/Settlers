#ifndef HOUSE_H
#define HOUSE_H
#include "building.h"
#include "terrain.h"
#include "settler.h"

class House: public Building {
public:
    House(Terrain *terrain, bool initialize);
    void addSettler(Settler *settler);
private:
    Terrain *terrain;
    std::vector<Settler*> habitants;
};

#endif
