#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QtWidgets>
#include "game.h"
#include "result.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
        void clicked();

private slots:
        void on_pushButton_clicked(int id );


        void on_pushButton_clicked();

        void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    void setlabel();
    QVector<QPushButton*> buttons;
    QSignalMapper *signalMapper;
    game gobj;
    void setImage(int , QPushButton*);
    int flag;
    int swaparr[2];
    void play(int , int , int , int);
    void resetImage();
    void checkWin();
    bool isNear(int , int , int , int);
    int step;
    Result *resWin;


};

#endif // MAINWINDOW_H
