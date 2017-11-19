#ifndef TERRAIN_H
#define TERRAIN_H
#include "coordinates.h"
#include <string>

class Terrain {
public:
    bool isBlocked();
    Coordinates getLocation();
    void toggleBlock();
    ~Terrain();
    int getType();
    void setType(int newType);

private:
    bool blocked;
    Coordinates location;
    int type;

};


#endif