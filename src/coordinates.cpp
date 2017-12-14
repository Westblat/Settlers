#include "coordinates.h"

Coordinates::Coordinates(int x, int y) : x(x), y(y){}
Coordinates::Coordinates(Coordinates &other){
    x = other.getX();
    y = other.getY();
}

int Coordinates::getX() const {return x;}
int Coordinates::getY() const {return y;}

bool Coordinates::updateCoords(int xVal, int yVal) {
    x = xVal;
    y = yVal;
    return true;
}

bool Coordinates::updateCoords(Coordinates &coords) {
    x = coords.getX();
    y = coords.getY();
    return true;
}

bool operator==(Coordinates const&a, Coordinates const&b) {
    return a.getX()==b.getX() && a.getY()==b.getY();
}
bool operator!=(Coordinates const&a, Coordinates const&b) {
    return a.getX()!=b.getX() || a.getY()!=b.getY();
}

std::ostream& operator <<(std::ostream& os, Coordinates& coordinates){
    os << "(";
    os << coordinates.getX();
    os << ",";
	os << coordinates.getY();
    os << ")";
	return os;
}
