#include "mainwindow.h"
#include "gamewindow.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    setWindowTitle("The Settlers");
    setMinimumSize(300, 200);


    grid = new QGridLayout;
    //grid->setSpacing(5);
    setLayout(grid);

    quit_button = new QPushButton();
    quit_button->setIcon(QIcon(":/graphics/menuicon_quit.png"));
    quit_button->setIconSize(QSize(300,50));
    quit_button->setFlat(true);

    start_button = new QPushButton();
    start_button->setIcon(QIcon(":/graphics/menuicon_newgame.png"));
    start_button->setIconSize(QSize(300,50));
    start_button->setFlat(true);

    grid->addWidget(quit_button, 0, 0);
    grid->addWidget(start_button, 1, 0);

    //connect(quit_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
    connect(quit_button, SIGNAL (clicked()), this, SLOT (close()));

    connect(start_button, SIGNAL (clicked()), this , SLOT (NewGame()));
}

void Window::NewGame() {
    gamewindow = new GameWindow(this);
    gamewindow->show();

    // hide "New game"-button
    start_button->hide();

    // add a button for resuming the game
    resume_button =  new QPushButton();
    resume_button->setIcon(QIcon(":/graphics/menuicon_resumegame.png"));
    resume_button->setIconSize(QSize(300,50));
    resume_button->setFlat(true);
    grid->addWidget(resume_button, 1, 0);
    connect(resume_button, SIGNAL(clicked()), this, SLOT(ResumeGame()));
}

void Window::ResumeGame() {
    gamewindow->show();
}