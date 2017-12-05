#ifndef BUILDINGITEM_H
#define BUILDINGITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsView>

class BuildingItem : public QGraphicsRectItem {
public:
	BuildingItem(int tilesize, int type);
};

#endif