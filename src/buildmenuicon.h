#ifndef BUILDMENUICON_H
#define BUILDMENUICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class BuildmenuIcon : public QGraphicsPixmapItem {
public:
	BuildmenuIcon(int type, QGraphicsItem *parent = 0);
};

#endif