#include <QApplication>
#include <windows.h>
#include <QDebug>
#include "mainwindow.h"
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand( static_cast<unsigned int>(time(nullptr)));
    Dialog d;
    MainWindow w;
    w.boardInitialize();
    w.execute();
//    d.show();
    return a.exec();
}
