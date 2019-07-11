#include "PlayerPiece.h"

PlayerPiece::PlayerPiece()
{
    tilePos = 0;
}

PlayerPiece::~PlayerPiece()
{
    //dtor
}

string setPlayerName(string name)
{
    cout << "Enter your name" << endl;
    cin >> name;
    return name;
}

void mover(int steps)
{
    if (turn == TRUE)
    {
        tilePos += steps;
    }
    return 0;
}
