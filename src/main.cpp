#include "mainwindow.h"
#include <QApplication>
#include "gamewindow.h"

Window * w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    //Main Menu when opening program
    w = new Window();
    w->show();

    return a.exec();
}
