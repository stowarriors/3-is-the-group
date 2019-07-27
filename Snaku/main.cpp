#include <QApplication>
#include <windows.h>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand( static_cast<unsigned int>(time(nullptr)));
    MainWindow w;
    w.boardInitialize();
    w.execute();
    return a.exec();
}
