#ifndef BUILDINGITEM_H
#define BUILDINGITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class BuildingItem : public QGraphicsPixmapItem {
public:
    BuildingItem(int buildingtype, bool ready, int health, int x, int y, QGraphicsItem *parent = 0);
	bool getReadiness() {return readiness;};
	int getType() {return type;};
	int getHP() {return hp;};
    int getX() {return x;};
    int getY() {return y;};
private:
	bool readiness;
	int type;
	int hp;
    int x;
    int y;
};

#endif
