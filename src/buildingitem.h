#ifndef BUILDINGITEM_H
#define BUILDINGITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class BuildingItem : public QGraphicsPixmapItem {
public:
	BuildingItem(int buildingtype, bool ready, int health, QGraphicsItem *parent = 0);
	bool getReadiness() {return readiness;};
	int getType() {return type;};
	int getHP() {return hp;};
private:
	bool readiness;
	int type;
	int hp;
};

#endif