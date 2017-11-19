#ifndef TERRAIN_H
#define TERRAIN_H
#include "coordinates.h"

class Terrain {
public:
    Terrain(Coordinates *coord, int type);
    ~Terrain();
    
    bool isBlocked();
    void toggleBlock();
    
    int getType();
    void setType(int newType);
    
    Coordinates getLocation();

private:
    Coordinates *location;
    int type;
    bool blocked;

};


#endif