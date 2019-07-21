#include "mainwindow.h"
#include "board.h"
#include "movehandle.h"
#include "movehandle2.h"
#include <QApplication>
#include <windows.h>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Board b;
    MoveHandle m1;
    MoveHandle2 m2;

    double xe1 = 4;
    double xe2 = 12;
    double ye1 = 107.5;
    double ye2 = 107.5;

    QGraphicsScene * scene = new QGraphicsScene(-130,-200,500,500);
    int x1 = 0;
    while (x1 != 250)
    {
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(x1,0,20,20);
        rect->setBrush(Qt::yellow);
        scene->addItem(rect);
        if (x1 == 225) {break;}
        x1=x1+25;
    }
    int x2 = 0;
    while (x2 != 250)
    {
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(x2,25,20,20);
        rect->setBrush(Qt::yellow);
        scene->addItem(rect);
        if (x2 == 225) {break;}
        x2=x2+25;
    }
    int x3 = 0;
    while (x3 != 250)
    {
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(x3,50,20,20);
        rect->setBrush(Qt::yellow);
        scene->addItem(rect);
        if (x3 == 225) {break;}
        x3=x3+25;
    }
    int x4 = 0;
    while (x4 != 250)
    {
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(x4,75,20,20);
        rect->setBrush(Qt::yellow);
        scene->addItem(rect);
        if (x4 == 225) {break;}
        x4=x4+25;
    }
    int x5 = 0;
    while (x5 != 250)
    {
        QGraphicsRectItem * rect = new QGraphicsRectItem();
        rect->setRect(x5,100,20,20);
        rect->setBrush(Qt::yellow);
        scene->addItem(rect);
        if (x5 == 225) {break;}
        x5=x5+25;
    }
    MoveHandle * player1 = new MoveHandle();
    player1->setRect(xe1,ye1,5,5);
    player1->setBrush(Qt::red);
    scene->addItem(player1);

    MoveHandle2 * player2 = new MoveHandle2();
    player2->setRect(xe2,ye2,5,5);
    player2->setBrush(Qt::blue);
    scene->addItem(player2);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();




















    w.execute();
//    b.boardInitialize();
    w.show();
    for (int x=0;x<10;++x)
    {
        m1.getMove();
    }
    b.boardInitialize();
    return a.exec();
}
