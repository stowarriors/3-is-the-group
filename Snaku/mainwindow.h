#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <board.h>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int roll;
    void execute();
public slots:
    void dieRoll();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
