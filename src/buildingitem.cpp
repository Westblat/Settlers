#include "buildingitem.h"

BuildingItem::BuildingItem(int tilesize, int type) {
	//rectangles are placeholders inb4 .png files

	setRect(0,0,tilesize,tilesize);

	if (type == 0) {												// 0: TREE
		QBrush brush = QBrush(QColor(0, 255, 0)); // Bright green
		setBrush(brush);
	}
	else if (type == 1) {											// 1: HOUSE
		QBrush brush = QBrush(QColor(51, 25, 0)); // Brownish
		setBrush(brush);
	}
	else if (type == 2) {											// 2: WAREHOUSE
		QBrush brush = QBrush(QColor(255, 128, 0)); // Orange
		setBrush(brush);
	}
}