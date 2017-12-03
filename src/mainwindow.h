#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtWidgets>

//window showing the actual game
//opens when new game is started from main menu
class GameWindow;

//this is the main window, so called "Main Menu", for the program itself.
class Window : public QWidget {
	Q_OBJECT

public:
 	explicit Window(QWidget *parent = 0);

private:
 	QPushButton *quit_button;
 	QPushButton *start_button;
 	GameWindow *gamewindow;


private slots:
	void OpenGameWindow();

};

#endif // MAINWINDOW_H