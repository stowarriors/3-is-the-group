#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "players.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QThread>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execute()
{   
//    player1Name->setGeometry(QRect(20,100,50,18));
//    player1Name->setText("Enter Player1 Name");

//    player2Name->setGeometry(QRect(20,120,50,18));
//    player2Name->setText("Enter Player2 Name");

//    QPushButton * enter1 = new QPushButton(this);
//    enter1->setGeometry(QRect(130,100,60,18));
//    enter1->setText("Enter");
//    QObject::connect(enter1, SIGNAL(clicked()),this,SLOT(getName1()));

//    QPushButton * enter2 = new QPushButton(this);
//    enter2->setGeometry(QRect(130,120,60,18));
//    enter2->setText("Enter");
//    QObject::connect(enter2, SIGNAL(clicked()),this,SLOT(getName2()));


//    QPushButton * dieButton = new QPushButton(this);
//    dieButton->setGeometry(QRect(20,250,70,25));
//    dieButton->setText("Roll the die");

//    QPushButton * dieButton2 = new QPushButton(this);
//    dieButton2->setGeometry(QRect(50,250,140,50));
//    dieButton2->setText("TESTBUTTON");
//    QObject::connect(ui->dieRoll, SIGNAL(clicked()),this,SLOT(dieRoll()));

//    QWidget* centralWidget = new QWidget(this);
//    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//    QHBoxLayout * layout1 = new QHBoxLayout(centralWidget);
//    layout1->setMargin(100);
//    layout1->addWidget(player1Name);
//    layout1->addWidget(player2Name);
//    setCentralWidget(centralWidget);

    show();
}

void MainWindow::boardInitialize()
{
//        QGraphicsScene *scene = new QGraphicsScene(-130,-200,500,500);
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
            rect->setBrush(Qt::black);
            scene->addItem(rect);
            if (x2 == 225) {break;}
            x2=x2+25;
        }
        int x3 = 0;
        while (x3 != 250)
        {
            QGraphicsRectItem * rect = new QGraphicsRectItem();
            rect->setRect(x3,50,20,20);
            rect->setBrush(Qt::green);
            scene->addItem(rect);
            if (x3 == 225) {break;}
            x3=x3+25;
        }
        int x4 = 0;
        while (x4 != 250)
        {
            QGraphicsRectItem * rect = new QGraphicsRectItem();
            rect->setRect(x4,75,20,20);
            rect->setBrush(Qt::magenta);
            scene->addItem(rect);
            if (x4 == 225) {break;}
            x4=x4+25;
        }
        int x5 = 0;
        while (x5 != 250)
        {
            QGraphicsRectItem * rect = new QGraphicsRectItem();
            rect->setRect(x5,100,20,20);
            rect->setBrush(Qt::gray);
            scene->addItem(rect);
            if (x5 == 225) {break;}
            x5=x5+25;
        }
//        QGraphicsView * view = new QGraphicsView(scene);

//        player1->setRect(xe1,ye1,5,5);
//        player1->setBrush(Qt::red);
//        scene->addItem(player1);

//        player2->setRect(xe2,ye2,5,5);
//        player2->setBrush(Qt::blue);
//        scene->addItem(player2);
// Red Snakes
        snake1->setLine(85,110,35,35);
        snake1->setPen(QPen(Qt::red));
        scene->addItem(snake1);
        snake2->setLine(210,110,235,85);
        snake2->setPen(QPen(Qt::red));
        scene->addItem(snake2);
        snake3->setLine(210,85,210,10);
        snake3->setPen(QPen(Qt::red));
        scene->addItem(snake3);
        snake4->setLine(10,85,10,10);
        snake4->setPen(QPen(Qt::red));
        scene->addItem(snake4);
        snake5->setLine(160,60,185,35);
        snake5->setPen(QPen(Qt::red));
        scene->addItem(snake5);
        snake6->setLine(110,60,85,10);
        snake6->setPen(QPen(Qt::red));
        scene->addItem(snake6);
// White Ladders
        ladder1->setLine(110,110,135,60);
        ladder1->setPen(QPen(Qt::white));
        scene->addItem(ladder1);
        ladder2->setLine(185,85,185,60);
        ladder2->setPen(QPen(Qt::white));
        scene->addItem(ladder2);
        ladder3->setLine(35,85,85,35);
        ladder3->setPen(QPen(Qt::white));
        scene->addItem(ladder3);
        ladder4->setLine(135,35,110,10);
        ladder4->setPen(QPen(Qt::white));
        scene->addItem(ladder4);

        view->setBackgroundBrush(Qt::darkCyan);
        view->setWindowTitle("Snakes and Ladders");
        view->showMaximized();
}

void MainWindow::dieRoll()
{
    if (player == 1)
    {
        srand( static_cast<unsigned int>(time(nullptr)));
        rolled = rand() % 6 + 1;
        QString n = QString::number(rolled);
//        QString t = QString::number(player);
        QMessageBox msgBox;
        msgBox.setWindowTitle("DIE");
        msgBox.setText("Player "+s.p1Name+" Rolled "+n+" Turns.");
        msgBox.exec();
        for (int counter = 0;counter != rolled;++counter)
            {
                if (((rowCheckFlag1==1)||(rowCheckFlag1==3)||(rowCheckFlag1==5))&&((count1!=10)&&(count1!=30)&&(count1!=50)))
                {
                    player1->setRect(xe1+25,ye1,5,5);
                    //updates x to go to right
                    xe1 += 25;
                    ++count1;
                }
                else if (((rowCheckFlag1==2)||(rowCheckFlag1==4))&&((count1!=20)&&(count1!=40)))
                {
                    player1->setRect(xe1-25,ye1,5,5);
                    //updates x to go to left
                    xe1 -= 25;
                    ++count1;
                }
                else if ((count1==10)||(count1==20)||(count1==30)||(count1==40))
                {
                    player1->setRect(xe1,ye1-25,5,5);
                    //updates y to go up
                    ye1 -=25;
                    ++count1;
                    ++rowCheckFlag1;
                }
            }
        if (count1 == 50)
        {
            msgBox.setWindowTitle("Winner :))");
            msgBox.setText("Player "+s.p1Name+" WINS!!!!");
            msgBox.exec();
            ui->diceRoll->setEnabled(false);
            ui->pushButton_3->setEnabled(false);
        }
        switch (count1)
        {
        //Snake Tiles
        case 11:
            player1->setRect(204,107.5,5,5);
            xe1 = 204; ye1 = 107.5;
            count1 = 9;
            rowCheckFlag1 = 1;
            break;
        case 33:
            player1->setRect(154,57.5,5,5);
            xe1 = 154; ye1 = 57.5;
            count1 = 27;
            rowCheckFlag1 = 3;
            break;
        case 39:
            player1->setRect(79,107.5,5,5);
            xe1 = 79; ye1 = 107.5;
            count1 = 4;
            rowCheckFlag1 = 1;
            break;
        case 41:
            player1->setRect(4,82.5,5,5);
            xe1 = 4; ye1 = 82.5;
            count1 = 20;
            rowCheckFlag1 = 2;
            break;
        case 44:
            player1->setRect(104,57.5,5,5);
            xe1 = 104; ye1 = 57.5;
            count1 = 25;
            rowCheckFlag1 = 3;
            break;
        case 49:
            player1->setRect(204,82.5,5,5);
            xe1 = 204; ye1 = 82.5;
            count1 = 12;
            rowCheckFlag1 = 2;
            break;
        //Ladder Tiles
        case 5:
            player1->setRect(129,57.5,5,5);
            xe1 = 129; ye1 = 57.5;
            count1 = 26;
            rowCheckFlag1 = 3;
            break;
        case 13:
            player1->setRect(179,57.5,5,5);
            xe1 = 179; ye1 = 57.5;
            count1 = 28;
            rowCheckFlag1 = 3;
            break;
        case 19:
            player1->setRect(79,32.5,5,5);
            xe1 = 79; ye1 = 32.5;
            count1 = 37;
            rowCheckFlag1 = 4;
            break;
        case 35:
            player1->setRect(104,7.5,5,5);
            xe1 = 104; ye1 = 7.5;
            count1 = 45;
            rowCheckFlag1 = 5;
            break;
        }
        player = 2;
    }
    else if (player == 2)
    {
//        srand( static_cast<unsigned int>(time(nullptr)));
        rolled = rand() % 6 + 1;
        QString s = QString::number(rolled);
        QString t = QString::number(player);
        QMessageBox msgBox;
        msgBox.setWindowTitle("DIE");
        msgBox.setText("Player "+t+" Rolled "+s+" Turns.");
        msgBox.exec();
        for (int counter = 0;counter != rolled;++counter)
            {
                if (((rowCheckFlag2==1)||(rowCheckFlag2==3)||(rowCheckFlag2==5))&&((count2!=10)&&(count2!=30)&&(count2!=50)))
                {
                    player2->setRect(xe2+25,ye2,5,5);
                    xe2 += 25;
                    ++count2;
                }
                else if (((rowCheckFlag2==2)||(rowCheckFlag2==4))&&((count2!=20)&&(count2!=40)))
                {
                    player2->setRect(xe2-25,ye2,5,5);
                    xe2 -= 25;
                    ++count2;
                }
                else if ((count2==10)||(count2==20)||(count2==30)||(count2==40))
                {
                    player2->setRect(xe2,ye2-25,5,5);
                    ye2 -= 25;
                    ++count2;
                    ++rowCheckFlag2;
                }
            }
        if (count2 == 50)
        {
            msgBox.setWindowTitle("Winner :))");
            msgBox.setText("Player "+t+" WINS!!!!");
            msgBox.exec();
            ui->diceRoll->setEnabled(false);
            ui->pushButton_3->setEnabled(false);
        }
        switch (count2)
        {
        //Snake Tiles
        case 11:
            player2->setRect(212,107.5,5,5);
            xe2 = 212; ye2 = 107.5;
            count2 = 9;
            rowCheckFlag2 = 1;
            break;
        case 33:
            player2->setRect(162,57.5,5,5);
            xe2 = 162; ye2 = 57.5;
            count2 = 27;
            rowCheckFlag2 = 3;
            break;
        case 39:
            player2->setRect(87,107.5,5,5);
            xe2 = 87; ye2 = 107.5;
            count2 = 4;
            rowCheckFlag2 = 1;
            break;
        case 41:
            player2->setRect(12,82.5,5,5);
            xe2 = 12; ye2 = 82.5;
            count2 = 20;
            rowCheckFlag2 = 2;
            break;
        case 44:
            player2->setRect(112,57.5,5,5);
            xe2 = 112; ye2 = 57.5;
            count2 = 25;
            rowCheckFlag2 = 3;
            break;
        case 49:
            player2->setRect(212,82.5,5,5);
            xe2 = 212; ye2 = 82.5;
            count2 = 12;
            rowCheckFlag2 = 2;
            break;
        //Ladder Tiles
        case 5:
            player2->setRect(137,57.5,5,5);
            xe2 = 137; ye2 = 57.5;
            count2 = 26;
            rowCheckFlag2 = 3;
            break;
        case 13:
            player2->setRect(187,57.5,5,5);
            xe2 = 187; ye2 = 57.5;
            count2 = 28;
            rowCheckFlag2 = 3;
            break;
        case 19:
            player2->setRect(87,32.5,5,5);
            xe2 = 87; ye2 = 32.5;
            count2 = 37;
            rowCheckFlag2 = 4;
            break;
        case 35:
            player2->setRect(112,7.5,5,5);
            xe2 = 112; ye2 = 7.5;
            count2 = 45;
            rowCheckFlag2 = 5;
            break;
        }
        player = 1;
    }
}

void MainWindow::on_diceRoll_clicked()
{
    dieRoll();
}

void MainWindow::on_enterName1_clicked()
{
    s.p1Name = ui->firstPlayerName->text();
    qDebug() << s.p1Name;
}

void MainWindow::on_enterName2_clicked()
{
    s.p2Name = ui->secondPlayerName->text();
    qDebug() << s.p2Name;
}

void MainWindow::on_pushButton_clicked()
{
    player1->setRect(xe1,ye1,5,5);
    player1->setBrush(Qt::red);
    scene->addItem(player1);

    player2->setRect(xe2,ye2,5,5);
    player2->setBrush(Qt::blue);
    scene->addItem(player2);
    ui->diceRoll->setEnabled(true);
}
