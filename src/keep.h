#ifndef KEEP_H
#define KEEP_H
#include "building.h"
#include "terrain.h"

class Keep :public Building {
public:
    Keep(Terrain *terrain, bool initialize);
    ~Keep();
    Coordinates* getLocation();
private:
    Terrain *terrain;
};


#endif
