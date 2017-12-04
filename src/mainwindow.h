#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

#include <QToolBar>
#include <QAction>

#include <QStackedLayout>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "game.h"


class MainWindow : public QMainWindow {
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initToolBar();
    void initCentralWidget();
};

#endif // MAINWINDOW_H
