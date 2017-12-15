#ifndef TREE_H
#define TREE_H
#include "building.h"
#include "terrain.h"
#include "coordinates.h"


class Tree: public Building{
public:
    Tree(Terrain *terrain, bool initialize);
    ~Tree();
    Coordinates* getLocation();
    
private:
    Terrain *terrain;
};


#endif
