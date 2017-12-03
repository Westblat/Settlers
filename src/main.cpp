#include "mainwindow.h"
#include <QApplication>
//#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    //Main Menu when opening program
    Window w;
    w.show();

    return a.exec();
}
