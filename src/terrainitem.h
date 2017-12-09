#ifndef TERRAINITEM_H
#define TERRAINITEM_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class TerrainItem : public QGraphicsPixmapItem {
public:
	TerrainItem(int type, QGraphicsItem *parent = 0);
};

#endif