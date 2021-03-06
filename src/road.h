#ifndef ROAD_H
#define ROAD_H

#include "building.h"
#include "terrain.h"

class Road : public Building
{
public:
    Road(Terrain* terrain, bool initialize, int roadtype);
    ~Road();
    Coordinates* getLocation();
    
private:
    Terrain* terrain;
};

#endif // ROAD_H
