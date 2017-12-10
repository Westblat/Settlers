#ifndef BUILDINGITEM_H
#define BUILDINGITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class BuildingItem : public QGraphicsPixmapItem {
public:
	BuildingItem(int type, bool ready, int hp, QGraphicsItem *parent = 0);
};

#endif