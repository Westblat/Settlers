#include "settleritem.h"

SettlerItem::SettlerItem(int tilesize) {
	//rectangles are placeholders inb4 .png files
	setRect(0,0,tilesize,tilesize);
	QBrush brush = QBrush(QColor(255, 0, 0)); // Bright red
	setBrush(brush);

}