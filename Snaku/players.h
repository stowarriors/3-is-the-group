#ifndef PLAYERS_H
#define PLAYERS_H
#include <QString>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>


class Players
{
public:
    Players();
    QString p1Name;
    QString p2Name;
    std::stack<std::string> names;
    std::string winner;
    std::string player1;
    std::string player2;
    int totalTurn1 = 0;
    int totalTurn2 = 0;
    int smallerScore;
    void scoreSetter1();
    void scoreSetter2();
    void saveScore();
    void loadScore();
    QString search(QString);
};

#endif // PLAYERS_H
