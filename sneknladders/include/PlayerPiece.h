#ifndef PLAYERPIECE_H
#define PLAYERPIECE_H
#include <string>


class PlayerPiece
{
    string playerName;
    int playerNo;
    int tilePos;
    bool turn;
    string color;

    public:
        PlayerPiece();
        virtual ~PlayerPiece();
        string setPlayerName();
        void mover(int);
};

#endif // PLAYERPIECE_H
