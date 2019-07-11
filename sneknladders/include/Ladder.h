#ifndef LADDER_H
#define LADDER_H

class Ladder
{
    int startingTile;
    int endingTile;
    int setStartingTile(int);
    int setEndingTile(int);
    public:
        Ladder();
        virtual ~Ladder();
};

#endif // LADDER_H
