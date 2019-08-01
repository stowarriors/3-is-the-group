#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <string>
#include <QMessageBox>
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    std::string usern;
    std::string pass;
    std::string usernn;
    std::string passs;
    username = ui->lineEdit->text();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    password = ui->lineEdit_2->text();
    usern = username.toStdString();
    pass = password.toStdString();
    std::ifstream loginFile;
    loginFile.open("credentials.txt");
    if (!loginFile.is_open())
    {
        QMessageBox messages;
        messages.setWindowTitle("Login");
        messages.setText("Nope didn't find you!");
        messages.exec();
        return;
    }
    while (!loginFile.eof())
    {
        loginFile>>usernn>>passs;
        if ((usernn==usern)&&(passs==pass))
        {
            QMessageBox message;
            message.setWindowTitle("Login");
            message.setText("Hello user!");
            message.exec();
            close();
            loginFile.close();
            w.boardInitialize();
            w.execute();
            return;
        }
    }
    QMessageBox message;
    message.setWindowTitle("Login");
    message.setText("nope didn't find you!");
    message.exec();
}

void Dialog::on_pushButton_2_clicked()
{
    std::string user;
    std::string pass;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    user = username.toStdString();
    pass = password.toStdString();
    std::ofstream signupFile;
    signupFile.open("credentials.txt",std::ios_base::app);
    signupFile<<user<<" "<<pass<<std::endl;
    signupFile.close();
}

void Dialog::on_pushButton_3_clicked()
{
    remove("credentials.txt");
}
