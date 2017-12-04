#include "terrainitem.h"

TerrainItem::TerrainItem(int tilesize, int type) {
	setRect(0,0,tilesize,tilesize);

	if (type == 0) {		// GRASS
		QBrush brush = QBrush(QColor(51, 102, 0));
		setBrush(brush);
	}
	else if (type == 1) {	// BUILDING ???
		QBrush brush = QBrush(QColor(51, 25, 0));
		setBrush(brush);
	}
	else if (type == 2) {	// ROCKS ???
		QBrush brush = QBrush(QColor(160, 160, 160));
		setBrush(brush);
	}
	else if (type == 3) {	// COAST
		QBrush brush = QBrush(QColor(204, 204, 0));
		setBrush(brush);
	}
	else if (type == 4) {	// WATER
		QBrush brush = QBrush(QColor(0, 76, 153));
		setBrush(brush);
	}
}