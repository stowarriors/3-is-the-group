#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
    int startingTile;
    int endingTile;
    int setStartingTile(int);
    int setEndingTile(int);
    public:
        Snake();
        virtual ~Snake();
};

#endif // SNAKE_H
