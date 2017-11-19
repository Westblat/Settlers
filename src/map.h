#ifndef MAP_H
#define MAP_H
#include <vector>
#include "terrain.h"
#include "coordinates.h"

class Map {
public:
    Map(int w, int h);
    void setMap();
private:
    int width;
    int height;
    std::vector<std::vector<Terrain*> > map;
};

#endif