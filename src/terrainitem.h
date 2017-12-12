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
	//TerrainItem(int type, Terrain *terrainptr, QGraphicsItem *parent = 0);
	TerrainItem(int type, int coord_x, int coord_y, QGraphicsItem *parent = 0);
	//Terrain *getTerrain() {return terrain;};
	//int getX() {return x;};
	//int getY() {return y;};
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	//Terrain *terrain; // this was probably left dangling at some point during running
	int x;
	int y;

signals:
	//void clicked(Terrain *terrain);
	void clicked(int x, int y);
	//void rightclicked(Terrain *terrain);
	void rightclicked(int x, int y);
	//void clicked(int i);
};

#endif