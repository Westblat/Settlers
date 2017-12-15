#ifndef SETTLERITEM_H
#define SETTLERITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

#include "settler.h"

class SettlerItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	SettlerItem(int n, QGraphicsItem *parent = 0);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	int number;

signals:
	void clicked(int n);
};

#endif