#ifndef GAMEBOARD_H
#define GAMEBOARD_H


class GameBoard
{
    int totalTiles;
    int occuTile[];
    public:
        GameBoard();
        virtual ~GameBoard();
        void tileStatusCheck();
};

#endif // GAMEBOARD_H
