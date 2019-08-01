#include <QApplication>
#include <windows.h>
#include <QDebug>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand( static_cast<unsigned int>(time(nullptr)));
    Dialog d;
    d.show();
    return a.exec();
}
