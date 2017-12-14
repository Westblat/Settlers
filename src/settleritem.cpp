#include "settleritem.h"

SettlerItem::SettlerItem(int n, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	number = n;
	setPixmap(QPixmap(":/graphics/settler.png"));
}

void SettlerItem::mousePressEvent(QGraphicsSceneMouseEvent *) {
	emit clicked(number);
}