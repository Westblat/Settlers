#ifndef TERRAINITEM_H
#define TERRAINITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsView>

class TerrainItem : public QGraphicsRectItem {
public:
	TerrainItem(int tilesize, int type);
};

#endif