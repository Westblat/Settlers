#ifndef TERRAINITEM_H
#define TERRAINITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

#include "terrain.h"

class TerrainItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	TerrainItem(int type, Terrain *terrainptr, QGraphicsItem *parent = 0);
	Terrain *getTerrain() {return terrain;};
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	Terrain *terrain;

signals:
	void clicked(Terrain *terrain);
	void rightclicked(Terrain *terrain);
	//void clicked(int i);
};

#endif