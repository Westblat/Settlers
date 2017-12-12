#ifndef IRONCUTTER_H
#define IRONCUTTER_H

#include "building.h"
#include "terrain.h"

class Ironcutter : public Building{
public:
    Ironcutter(Terrain *terrain, bool initialize);
    ~Ironcutter();
    Coordinates* getLocation();
    void setReady();
private:
    Terrain *terrain;

};

#endif
