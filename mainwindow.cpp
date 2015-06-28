#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gobj.init();
    setlabel();
    flag = 1;
    step = 0;
    resWin = new Result;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setlabel()
{
    int count = 0;
    for(int row = 0 ; row<10 ; row++)
    {
        for(int col = 0 ; col<10 ; col++)
        {
                        buttons.append(new QPushButton);
                        ui->gridLayout->addWidget(buttons[count],row,col);

                        setImage(gobj.arr[row][col] , buttons[count]);

                        signalMapper = new QSignalMapper(this);
                        connect(buttons[count], SIGNAL(clicked()) , signalMapper , SLOT(map()));
                        signalMapper->setMapping(buttons[count],count);
                        connect(signalMapper, SIGNAL(mapped(int)),this, SLOT(on_pushButton_clicked(int)));
                        count++;
        }
    }

                         ui->gridLayoutWidget->setLayout(ui->gridLayout);
}

void MainWindow::on_pushButton_clicked(int id)
{
    int row , col;
    row = id/10;
    col = id%10;
    qDebug() << row <<col;

    if(flag == 1)
    {
        swaparr[0] = row;
        swaparr[1] = col;
        flag = 0;
    }
    else if(flag == 0)
    {
        play(swaparr[0],swaparr[1],row,col);
        flag = 1;
    }
}

void MainWindow::setImage(int id , QPushButton *tempbut)
{
    switch(id)
                            {
                                case 1:
                                tempbut->setIcon(QIcon("blue.png"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 2:
                                tempbut->setIcon(QIcon("red.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 3:
                                tempbut->setIcon(QIcon("yellow.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 4:
                                tempbut->setIcon(QIcon("orange.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 5:
                                tempbut->setIcon(QIcon("purple.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 6:
                                tempbut->setIcon(QIcon("green.png"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 7:
                                tempbut->setIcon(QIcon("col.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 8:
                                tempbut->setIcon(QIcon("row.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 9:
                                tempbut->setIcon(QIcon("bomb.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 10:
                                tempbut->setIcon(QIcon("star.jpg"));
                                tempbut->setIconSize(QSize(60,60));
                                break;
                                case 0:
                                tempbut->setIcon(QIcon(""));
                                tempbut->setIconSize(QSize(60,60));
                            }
}

void MainWindow::play(int row1, int col1 , int row2 , int col2)
{
    if(isNear(row1,col1,row2,col2))
    {
    if(gobj.arr[row1][col1] != gobj.arr[row2][col2])
    {
    gobj.swap(gobj.arr[row1][col1],gobj.arr[row2][col2]);
    if(gobj.arr[row1][col1]<7 && gobj.arr[row2][col2]<7)
    {
    if(!(gobj.checkLine(row1,col1)||gobj.checkLine(row2,col2)))
        gobj.swap(gobj.arr[row1][col1],gobj.arr[row2][col2]);
    }
    else if (gobj.arr[row1][col1] > 6 && gobj.arr[row2][col2]<7)
    {
    gobj.checkLine(row2,col2);
    gobj.typeBomb(gobj.arr[row1][col1],row1,col1,gobj.arr[row2][col2]);
    }
    else if (gobj.arr[row2][col2] > 6 && gobj.arr[row1][col1]<7)
    {
    gobj.checkLine(row1,col1);
    gobj.typeBomb(gobj.arr[row2][col2],row2,col2,gobj.arr[row1][col1]);
    }
    gobj.moveDown();
    resetImage();
    step++;
    ui->lcdNumber->display(gobj.score);
    ui->lcdNumber_2->display(step);
    checkWin();
    }
    }
}

void MainWindow::resetImage()
{
    int count = 0;
    for(int row = 0 ; row<10 ; row++)
    {
        for(int col = 0 ; col<10 ; col++)
        {
            setImage(gobj.arr[row][col] , buttons[count]);
            count++;
        }
        }
}

void MainWindow::on_pushButton_clicked()
{
    gobj.init();
    setlabel();
    flag = 1;
    gobj.score = 0;
    step = 0;
    ui->lcdNumber->display(gobj.score);
    ui->lcdNumber_2->display(step);
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << gobj.score;
    this->close();
    resWin->setTitle(0);
    resWin->setStarScore(0,gobj.score);
    resWin->show();
}

void MainWindow::checkWin()
{
    if(step > 15)
    {
        this->close();
        resWin->setTitle(0);
        resWin->setStarScore(0,gobj.score);
        resWin->show();
    }

    if(gobj.score > 100)
    {
        if(step<=5)
        {
            this->close();
            resWin->setTitle(1);
            resWin->setStarScore(3,gobj.score);
            resWin->show();
        }
        if(step<=10&&step>5)
        {
            this->close();
            resWin->setTitle(1);
            resWin->setStarScore(2,gobj.score);
            resWin->show();
        }
        if(step<=15&&step>10)
        {
            this->close();
            resWin->setTitle(1);
            resWin->setStarScore(1,gobj.score);
            resWin->show();
        }

    }
}

bool MainWindow::isNear(int r1, int c1, int r2, int c2)
{
    if(r1==r2 && (c1 == c2+1 || c1 == c2-1))
    {
            return true;
    }
    else if(c1==c2 && (r1==r2+1 || r1== r2-1))
    {
            return true;
    }
    else
        return false;

}
