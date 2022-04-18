#include "changedest.h"
#include "ui_changedest.h"
#include "transschedule.h"


changeDest::changeDest(QWidget *parent) :
    QDialog(parent),
    temptraveler(),
    ui(new Ui::changeDest)
{
    fa = static_cast<MainWindow*>(parentWidget());
    setUI();

    //信号与槽
    connect(ui->buttonBox,&QDialogButtonBox::accepted,
            this,[=]()
    {
        if(ui->expDest->currentIndex() != 0)
        {
            traveler old = fa->travelerList[static_cast<size_t>(fa->travelerIndex)];
            temptraveler.startStation = old.oneRoute[old.curRoute].terminalStation;
            temptraveler.targetStation = ui->expDest->currentIndex() - 1;
            qDebug() << "当前终点" << QString::fromStdString(transSchedule::cityList[static_cast<size_t>(temptraveler.startStation)])
                        << "更改终点" << QString::fromStdString(transSchedule::cityList[static_cast<size_t>(temptraveler.startStation)]);
            temptraveler.beginTime.setHMS(fa->getMasterTimeHour(),fa->getMasterTimeMin(),0);
            temptraveler.totalMin = old.totalMin;
            temptraveler.strategy = old.strategy;

            if(temptraveler.strategy == 1)
            {
                temptraveler.strategy = 0;
                temptraveler.timeLimited = 0;
            }

            if(temptraveler.targetStation != old.targetStation)
                emit sendData(temptraveler);
        }
    });

}

changeDest::~changeDest()
{
    delete ui;
}

void changeDest::setUI()
{
    ui->setupUi(this);
    ui->finalDest->setReadOnly(true);
    ui->curDest->setReadOnly(true);
    this->setWindowTitle("更改目的地窗口");

    int n = transSchedule::max_city_number;
    auto it = transSchedule::cityList.begin();

    ui->expDest->addItem("请选择");
    traveler old = fa->travelerList[static_cast<size_t>(fa->travelerIndex)];
    ui->finalDest->setText(QString::fromStdString(transSchedule::cityList
                                                  [static_cast<size_t>(old.oneRoute.rbegin()->terminalStation)]));
    ui->curDest->setText(QString::fromStdString(transSchedule::cityList
                                                [static_cast<size_t>(old.oneRoute[old.curRoute].terminalStation)]));
    for(int i = 0; i < n ; ++i, ++it)
    {
        ui->expDest->addItem(QString::fromStdString(*it));
    }
}
