#ifndef ROAD_H
#define ROAD_H


class Road : public Building
{
public:
    Road(Terrain* terrain, bool initialze);
    ~Road();
};

#endif // ROAD_H
