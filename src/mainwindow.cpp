#include "mainwindow.h"
#include "gamewindow.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    setWindowTitle("The Settlers");
    setMinimumSize(800, 600);


    QGridLayout *grid = new QGridLayout;
    //grid->setSpacing(5);

    quit_button = new QPushButton("Quit");
    start_button = new QPushButton("New game");

    grid->addWidget(quit_button, 0, 0);
    grid->addWidget(start_button, 1, 0);

    setLayout(grid);

    connect(quit_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));

    connect(start_button, SIGNAL (clicked()), this , SLOT (OpenGameWindow()));
}

void Window::OpenGameWindow() {
    gamewindow = new GameWindow(this);
    //gamewindow = new GameWindow();
    gamewindow->show();
}