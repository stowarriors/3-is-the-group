#include "players.h"
#include <fstream>
#include <queue>
#include <QDebug>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>

Players::Players()
{
}

void Players::scoreSetter1()
{
    player1 = p1Name.toStdString();
    winner = player1;
    smallerScore = totalTurn1;
}

void Players::scoreSetter2()
{
    player2 = p2Name.toStdString();
    winner = player2;
    smallerScore = totalTurn2;
}

void Players::saveScore()
{
    if (smallerScore > 99)
    {
        smallerScore = 99;
    }
    std::ofstream saver;
    saver.open("scores.txt",std::ios_base::app);
    saver<<smallerScore<<" "<<winner<<std::endl;
    saver.close();
}

void Players::loadScore()
{
    std::string name;
    std::ifstream loader;
    loader.open("scores.txt");
    std::stack<std::string> names;
    while (!loader.eof())
    {
        std::getline(loader,name);
        names.push(name);
        QString str = QString::fromUtf8(names.top().c_str());
        qDebug()<<str;
        qDebug()<<names.size();
    }
    loader.close();
    std::vector<std::string> namees;
    unsigned bse = 0;
    int flag = 0;
    unsigned long long size = names.size();
    while (bse!=size)
    {      
        if (flag == 0)
        {
          names.pop();
          flag = 1;
        }
        else if (flag == 1)
        {
          namees.push_back(names.top());
          names.pop();
        }
        ++bse;
    }
    std::sort(namees.begin(),namees.end());
    std::ofstream sortedSaver;
    sortedSaver.open("sortedSaver.txt");
    for (unsigned i=0; i<namees.size();++i)
    {
    sortedSaver<<"Score: "<<namees[i]<<std::endl;
    }
}

QString Players::search(QString s)
{
    std::string str=s.toStdString();
    std::regex h(str,std::regex_constants::icase);
    std::string search;
    std::ifstream loader;
    std::smatch matches;
    loader.open("scores.txt");
    while (!loader.eof())
    {
        std::getline(loader,search);
        if (std::regex_search(search,matches,h) == true)
        {
            str = search;
            break;
        }
        else if (std::regex_search(search,matches,h) == false)
        {
            str = "not found :c";
        }
    }
    QString strs = QString::fromUtf8(str.c_str());
    return (strs);
}
