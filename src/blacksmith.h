#ifndef BLACKSMITH_H
#define BLACKSMITH_H

#include "building.h"
#include "terrain.h"
#include "settler.h"

class Blacksmith : public Building {
public:
	Blacksmith(Terrain *terrain, bool initialize);
	void addSettler(Settler *settler);
    bool makeWeapon();
    Coordinates* getLocation();
private:
    Terrain *terrain;
};

#endif

