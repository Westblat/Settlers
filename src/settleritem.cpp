#include "settleritem.h"

SettlerItem::SettlerItem(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap(":/graphics/settler.png"));
}