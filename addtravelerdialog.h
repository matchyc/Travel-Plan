#ifndef ADDTRAVELERDIALOG_H
#define ADDTRAVELERDIALOG_H
#include "traveler.h"
#include "transschedule.h"

#include <QDialog>

namespace Ui {
class addTravelerDialog;
}

class addTravelerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addTravelerDialog(QWidget *parent = nullptr);
    ~addTravelerDialog();

    void setUI();

    traveler tempTraveler;

private:
    Ui::addTravelerDialog *ui;

signals:
    void sendData(traveler data);
};

#endif // ADDTRAVELERDIALOG_H
