#include "settleritem.h"

SettlerItem::SettlerItem(Settler *settlerptr, QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	settler = settlerptr;
	setPixmap(QPixmap(":/graphics/settler.png"));
}

void SettlerItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	emit clicked();
}