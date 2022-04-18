#ifndef CHANGEDEST_H
#define CHANGEDEST_H

#include <QDialog>
#include "traveler.h"
#include "mainwindow.h"

namespace Ui {
class changeDest;
}

class changeDest : public QDialog
{
    Q_OBJECT

public:
    explicit changeDest(QWidget *parent = nullptr);
    ~changeDest();

    void setUI();

    traveler temptraveler;


private:
    Ui::changeDest *ui;
    MainWindow* fa;

signals:
    void sendData(traveler data);
};

#endif // CHANGEDEST_H
