#ifndef MAP_H
#define MAP_H
#include <vector>
#include "terrain.h"
#include "coordinates.h"
#include <iostream>

class Map {
public:
    Map(int w, int h);
    ~Map();
    int get_width() const;
    int get_height() const;
    const std::vector<std::vector<Terrain*> >& get_map() const;
    void setMap();
private:
    int width;
    int height;
    std::vector<std::vector<Terrain*> > map;
};

std::ostream& operator<<(std::ostream& os, Map map);

#endif
