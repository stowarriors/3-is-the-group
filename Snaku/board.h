#ifndef BOARD_H
#define BOARD_H
#include <QPushButton>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include "movehandle.h"
#include "movehandle2.h"

class Board
{
    friend class MoveHandle;
    friend class Movehandle2;
public:
    Board();
    void boardInitialize();
//    void lol();
//    QGraphicsScene * scene = new QGraphicsScene(-130,-200,500,500);
    double xe1 = 4;
    double xe2 = 12;
    double ye1 = 107.5;
    double ye2 = 107.5;

};

#endif // BOARD_H
