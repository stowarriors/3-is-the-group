#ifndef MOVEHANDLE_H
#define MOVEHANDLE_H
#include <QGraphicsRectItem>

class MoveHandle: public QGraphicsRectItem
{
public:
    MoveHandle();
    void getMove();
};

#endif // MOVEHANDLE_H
