#ifndef BLACKSMITH_H
#define BLACKSMITH_H

#include "building.h"
#include "terrain.h"
#include "settler.h"

class Blacksmith : public Building {
public:
	Blacksmith(Terrain *terrain, bool initialize);
	void addSettler(Settler *settler);
	void makeWeapon();
private:
	Terrain *terrain;
	std::vector<Settler*> habitants;
};

#endif

