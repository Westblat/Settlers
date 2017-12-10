#ifndef TERRAINITEM_H
#define TERRAINITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "terrain.h"

class TerrainItem : public QGraphicsPixmapItem {
public:
	TerrainItem(int type, Terrain *terrainptr, QGraphicsItem *parent = 0);
	Terrain *getTerrain() {return terrain;};
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	Terrain *terrain;
};

#endif