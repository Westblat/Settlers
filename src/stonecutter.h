#ifndef STONECUTTER_H
#define STONECUTTER_H

#include "building.h"
#include "terrain.h"

class Stonecutter : public Building {
public:
    Stonecutter(Terrain *terrain, bool initialize);
    ~Stonecutter();
    Coordinates* getLocation();
    void setReady();
private:
    Terrain *terrain;

};

#endif