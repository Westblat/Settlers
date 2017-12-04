#ifndef MAP_H
#define MAP_H
#include <climits>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include "priorityqueue.h"


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
