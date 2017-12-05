#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "game.h"
#include "map.h"

class Map;

//window showing the actual game
//opens when new game is started from main menu
class GameWindow : public QWidget {
	Q_OBJECT

public:
	explicit GameWindow(QWidget *parent = 0);
	void draw_terrain(QGraphicsScene* scene);


private:
	Game game; // creates the game
	Map map = game.getMap();

	QPushButton *menu_button;

public slots:
	void ShowMainMenu();
};

#endif