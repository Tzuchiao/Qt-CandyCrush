#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    setTitle(2);
    setStarScore(1,5);
}

Result::~Result()
{
    delete ui;
}

void Result::setTitle(int pass)
{
    if(pass == 1)
    {
        ui->label->setText("Pass");
    }
    else
    {
        ui->label->setText("Failed");
    }
}

void Result::setStarScore(int star, int score)
{
    ui->label_2->setText("star : " + QString::number(star));
    ui->label_3->setText("score : " + QString::number(score));
}

void Result::on_pushButton_clicked()
{
    this->close();
}
