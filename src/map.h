#ifndef MAP_H
#define MAP_H
#include <vector>
#include "terrain.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "priorityqueue.h"
#include <stack>


class Map {
public:
    Map(int w, int h);
    ~Map();
    int get_width() const;
    int get_height() const;
    const std::vector<std::vector<Terrain*> >& get_map() const;
    void setMap();
    bool contains(Coordinates &coord);
    bool contains(int x, int y);
    Terrain* getTerrain(Coordinates *coord);
    Terrain* getTerrain(int x, int y);
    std::stack<std::pair<int, int> > solvePath(Coordinates* unit, Coordinates* target);
private:
    int width;
    int height;
    std::vector<std::vector<Terrain*> > map;
};


std::ostream& operator<<(std::ostream& os, Map& map);

#endif
