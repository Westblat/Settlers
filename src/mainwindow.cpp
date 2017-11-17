#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowTitle("Le Settlers");

    initToolBar();
    initCentralWidget();

}

MainWindow::~MainWindow() {

}


void MainWindow::initToolBar() {

    QToolBar * tb = new QToolBar(this);
    tb->setMovable(false);

    QAction * tb_exit = new QAction("Exit", tb);
    QAction * tb_help = new QAction("Help", tb);

    tb->addAction(tb_exit);
    tb->addAction(tb_help);
    this->addToolBar(tb);
}


void MainWindow::initCentralWidget() {

    QWidget * centralWidget = new QWidget(this);
    QStackedLayout * stackedLayout = new QStackedLayout(centralWidget);

    QWidget * mm_widget = new QWidget(centralWidget); //mm stands for main menu
    mm_widget->setMinimumSize(120,120);

    QHBoxLayout * mm_layout = new QHBoxLayout(mm_widget);
    QGroupBox * mm_box = new QGroupBox("Start a new game", mm_widget);
    QGridLayout * mm_grid = new QGridLayout(mm_box);
    QPushButton * mm_button = new QPushButton("Play", mm_widget);

    mm_grid->addWidget(mm_button);
    mm_box->setLayout(mm_grid);
    mm_box->setMaximumSize(150,90);
    mm_layout->addWidget(mm_box);
    mm_widget->setLayout(mm_layout);

    stackedLayout->addWidget(mm_widget);
    centralWidget->setLayout(stackedLayout);
    this->setCentralWidget(centralWidget);
}
