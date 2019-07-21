#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QPushButton * dieButton = new QPushButton(this);
    dieButton->setGeometry(QRect(20,250,70,25));
    dieButton->setText("Rolls The Die");

    QObject::connect(dieButton, SIGNAL(clicked()),this,SLOT(dieRoll()));

//    QWidget* centralWidget = new QWidget(this);
//    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

//    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
//    layout->addWidget(dieButton);

//    setCentralWidget(centralWidget);
    setWindowTitle("Pushbutton Clicked Signal Test");
    show();
}

void MainWindow::dieRoll()
{
//    int min = 0;
//    int max = 6;
//    int i;
//    QRandomGenerator generate;
//    i = generate.bounded(min,max);
//    roll = i;
    QMessageBox msgBox;
        msgBox.setWindowTitle("MessageBox Title");
        msgBox.setText("You Clicked The Die");
        msgBox.exec();
}
