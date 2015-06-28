#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include "result.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private:
    Ui::StartWindow *ui;

protected:
    Result *resWin;

};

#endif // STARTWINDOW_H
