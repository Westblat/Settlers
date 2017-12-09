#ifndef BUILDINGITEM_H
#define BUILDINGITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsView>

class BuildingItem : public QGraphicsPixmapItem {
public:
	BuildingItem(int type, QGraphicsItem *parent = 0);
};

#endif