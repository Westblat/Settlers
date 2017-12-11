#include "cmdmenuicon.h"

cmdMenuIcon::cmdMenuIcon(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap(":/graphics/cmdicon.png"));
}