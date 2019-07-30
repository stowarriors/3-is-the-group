#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QLineEdit>
//#include <QGraphicsView>
#include <QGraphicsScene>
#include <players.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Players s;
    int rolled;
    int player = 1;
    int rowCheckFlag1 = 1;
    int rowCheckFlag2 = 1;
    int count1=1;
    int count2=1;
    bool startFlag = false;
    int enterNameFlag1 = 0;
    int enterNameFlag2 = 0;
    double xe1 = 4;
    double xe2 = 12;
    double ye1 = 107.5;
    double ye2 = 107.5;
    QGraphicsRectItem *player1 = new QGraphicsRectItem();
    QGraphicsRectItem *player2 = new QGraphicsRectItem();
    QGraphicsLineItem *snake1 = new QGraphicsLineItem();
    QGraphicsLineItem *snake2 = new QGraphicsLineItem();
    QGraphicsLineItem *snake3 = new QGraphicsLineItem();
    QGraphicsLineItem *snake4 = new QGraphicsLineItem();
    QGraphicsLineItem *snake5 = new QGraphicsLineItem();
    QGraphicsLineItem *snake6 = new QGraphicsLineItem();
    QGraphicsLineItem *ladder1 = new QGraphicsLineItem();
    QGraphicsLineItem *ladder2 = new QGraphicsLineItem();
    QGraphicsLineItem *ladder3 = new QGraphicsLineItem();
    QGraphicsLineItem *ladder4 = new QGraphicsLineItem();
    QGraphicsScene * scene = new QGraphicsScene(-130,-200,500,500);
//    QGraphicsView * view = new QGraphicsView(scene);
    void execute();
    void boardInitialize();
public slots:
    void dieRoll();
private slots:
    void on_diceRoll_clicked();

    void on_enterName1_clicked();

    void on_enterName2_clicked();

    void on_pushButton_clicked();

    void on_winnersButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
