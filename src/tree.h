#ifndef TREE_H
#define TREE_H
#include "building.h"
#include "terrain.h"


class Tree: public Building{
public:
    Tree(Terrain *terrain, bool initialize);
    void build();
    ~Tree();
private:
    Terrain *terrain;
};


#endif