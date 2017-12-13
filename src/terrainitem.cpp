#include "terrainitem.h"

TerrainItem::TerrainItem(int type, int coord_x, int coord_y, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	x = coord_x;
	y = coord_y;

	if (type == 0) {		// 0: GRASS/PLAINS
		setPixmap(QPixmap(":/graphics/grass.png"));
	}
	else if (type == 1) {	// 1: STONE
		setPixmap(QPixmap(":/graphics/stone.png"));
	}
	else if (type == 2) {	// 2: MOUNTAIN
		setPixmap(QPixmap(":/graphics/mountain.png"));
	}
	else if (type == 3) {	// 3: BEACH
		setPixmap(QPixmap(":/graphics/beach.png"));
	}
	else if (type == 4) {	// 4: WATER
		setPixmap(QPixmap(":/graphics/water.png"));
	}
}

void TerrainItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
    	emit rightclicked(x, y);
    }
    else {
    	emit clicked(x, y);
    }
}