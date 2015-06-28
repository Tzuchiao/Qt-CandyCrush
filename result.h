#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = 0);
    ~Result();
    void setTitle(int pass);
    void setStarScore(int star , int score);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
