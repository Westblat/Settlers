#ifndef BUILDMENUICON_H
#define BUILDMENUICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class BuildmenuIcon : public QGraphicsPixmapItem {
public:
	BuildmenuIcon(int type, QGraphicsItem *parent = 0);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	int type;
};

#endif