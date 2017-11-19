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
    bool blocked;
    Coordinates location;
    int type;

};


#endif