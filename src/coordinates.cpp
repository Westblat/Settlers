#include "coordinates.h"

Coordinates::Coordinates(int x, int y) : x(x), y(y){}

int Coordinates::get_x() const {return x;}
int Coordinates::get_y() const {return y;}

bool operator==(Coordinates const&a, Coordinates const&b) {
    return a.get_x()==b.get_x() && a.get_y()==b.get_y();
}

