#include "terrainitem.h"

TerrainItem::TerrainItem(int tilesize, int type) {
	//rectangles are placeholders inb4 .png files
	setRect(0,0,tilesize,tilesize);

	if (type == 0) {		// 0: GRASS/PLAINS
		QBrush brush = QBrush(QColor(51, 102, 0)); // GREEN
		setBrush(brush);
	}
	else if (type == 1) {	// 1: STONE
		QBrush brush = QBrush(QColor(160, 160, 160)); // LIGHT GRAY
		setBrush(brush);
	}
	else if (type == 2) {	// 2: MOUNTAIN
		QBrush brush = QBrush(QColor(64, 64, 64));  // DARK GRAY
		setBrush(brush);
	}
	else if (type == 3) {	// 3: BEACH
		QBrush brush = QBrush(QColor(204, 204, 0)); // YELLOWISH
		setBrush(brush);
	}
	else if (type == 4) {	// 4: WATER
		QBrush brush = QBrush(QColor(0, 76, 153)); // DARK BLUE
		setBrush(brush);
	}
}