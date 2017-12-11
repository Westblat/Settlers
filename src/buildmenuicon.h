#ifndef BUILDMENUICON_H
#define BUILDMENUICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class BuildmenuIcon : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	BuildmenuIcon(int type, QGraphicsItem *parent = 0);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	int type;

signals:
	void clicked();
};

#endif