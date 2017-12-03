#include "terrainitem.h"

TerrainItem::TerrainItem(int tilesize) {
	setRect(0,0,tilesize,tilesize);
	QBrush red = QBrush(QColor(255, 255, 0));
    setBrush(red);
}