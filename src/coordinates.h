#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
public:
    Coordinates(int x, int y);
    int get_x() const;
    int get_y() const;
    Coordinates get_next(int x, int y);
private:
    int x;
    int y;
};

bool operator==(Coordinates const& a, Coordinates const& b);

#endif // COORDINATES_H
