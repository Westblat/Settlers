#include "map.h"

Map::Map(int w, int h) : width(w), height(h) {
    for(int i = 0; i < width; i++){
        for(int j = 0; i < height; i++){
            map[i][j] = new Terrain(new Coordinates(i,j),0);
        }
    }
}

