#include "addtravelerdialog.h"
#include "ui_addtravelerdialog.h"
#include <unordered_map>
#include <QString>
#include <string>
#include <QComboBox>
#include <QDebug>
#include "mainwindow.h"

addTravelerDialog::addTravelerDialog(QWidget *parent) :
    QDialog(parent),tempTraveler(),
    ui(new Ui::addTravelerDialog)
{
    setUI();
    //信号与槽
    //出发地
    connect(ui->srcComboBox,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](){
        tempTraveler.startStation = ui->srcComboBox->currentIndex()-1;
//        qDebug() << tempTraveler.startStation;
    });

    //目的地
    connect(ui->destComboBox,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](){
        tempTraveler.targetStation = ui->destComboBox->currentIndex()-1;
//        qDebug() << tempTraveler.targetStation;
    });

    //策略选择
    connect(ui->strategyComboBox,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](){

        tempTraveler.strategy = ui->strategyComboBox->currentIndex() - 1;

        if(tempTraveler.strategy == 1)
        {
            ui->limitEdit->setReadOnly(false);
            ui->limitEdit->setDisabled(false);
        }

//        qDebug() << tempTraveler.strategy;
    });

    //确认添加，传输数据
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this,[=](){
//       qDebug() << ui->limitEdit->text();
       tempTraveler.timeLimited = ui->limitEdit->text().toInt();
       tempTraveler.timeMark = 0;
       MainWindow* fa = static_cast<MainWindow*>(parentWidget());
       tempTraveler.beginTime.setHMS(fa->getMasterTimeHour(),fa->getMasterTimeMin(),0);
       tempTraveler.travelMin = fa->getMasterTimeMin();
       tempTraveler.totalMin = tempTraveler.travelMin;
//       tempTraveler.travelHour = fa->getMasterTimeHour();
//       qDebug() << tempTraveler.beginTime.toString("hh:mm");
//       qDebug() << tempTraveler.timeLimited;
       if(tempTraveler.targetStation != tempTraveler.startStation)
        emit sendData(tempTraveler);
    });


}

void addTravelerDialog::setUI()
{
    ui->setupUi(this);
    this->setWindowTitle("添加旅客窗口");

    int n = transSchedule::max_city_number;
    auto it = transSchedule::cityList.begin();
    ui->srcComboBox->setFixedWidth(90);
    ui->destComboBox->setFixedWidth(90);
    ui->strategyComboBox->setFixedWidth(100);
    ui->srcComboBox->addItem("请选择");
    ui->destComboBox->addItem("请选择");
    ui->strategyComboBox->addItem("请选择");
    for(int i = 0; i < n ; ++i, ++it)
    {
        ui->srcComboBox->addItem(QString::fromStdString(*it));
        ui->destComboBox->addItem(QString::fromStdString(*it));
    }
    ui->strategyComboBox->addItem("最低风险");
    ui->strategyComboBox->addItem("限时最低风险");
    ui->limitEdit->setText("0");
    ui->limitEdit->setReadOnly(true);
    ui->limitEdit->setDisabled(true);
    ui->limitEdit->setValidator(new QIntValidator(1,9999,this));
}

addTravelerDialog::~addTravelerDialog()
{

    delete ui;
}
