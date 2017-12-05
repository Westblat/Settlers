#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
public:
    Coordinates(int x, int y);
    Coordinates(Coordinates &other);
    int getX() const;
    int getY() const;
    bool updateCoords(int x, int y);
private:
    int x;
    int y;
};

bool operator==(Coordinates const& a, Coordinates const& b);

#endif // COORDINATES_H
