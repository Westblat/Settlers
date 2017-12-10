#ifndef TERRAINITEM_H
#define TERRAINITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class TerrainItem : public QGraphicsPixmapItem {
public:
	TerrainItem(int type, QGraphicsItem *parent = 0);
};

#endif