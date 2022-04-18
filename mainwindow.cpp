#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lookupallroutes.h"
#include "changedest.h"
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QMovie>
#include <QLabel>

int MainWindow::travelerIndex = -1;
int MainWindow::timerInterval = 1000/6;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    speech = new QTextToSpeech(this); //设定语音播放器

    //设置好各个模块
    setMytravelPlanUI();
    setMasterTimer();
    setAddButton();
    setInquireComboBox();
    setLookUpButton();
    setChangeDestButton();
    setCitySecurityButton();

    //新增快速、慢速模式
    connect(this,SIGNAL(startTimer()),masterTimer,SLOT(start()));
    connect(ui->action_1h_s,&QAction::triggered,this,[=](){
       masterTimer->setInterval(1000/60);
       emit this->startTimer();
    });
    connect(ui->action_1h_10s,&QAction::triggered,this,[=](){
        masterTimer->setInterval(1000/6);
        emit this->startTimer();
    });
    connect(ui->action_1h_s,&QAction::triggered,ui->myMap,[=](){
        ui->myMap->paintTimer->setInterval(1000/60);
        emit this->startTimer();
    });
    connect(ui->action_1h_s,&QAction::triggered,ui->myMap,[=](){
        ui->myMap->paintTimer->setInterval(1000/6);
        emit this->startTimer();
    });
}



void MainWindow::setInquireComboBox()
{
    connect(ui->checkTravcomboBox,static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),this,[=](){
        if(ui->checkTravcomboBox->currentIndex() == 0)
            ui->changeDestButton->setEnabled(false);
        if(ui->checkTravcomboBox->currentIndex() != 0)
        {
            ui->changeDestButton->setEnabled(true);
            qDebug() << "切换到第" << ui->checkTravcomboBox->currentIndex() - 1<< "个游客的计划和动画展示";
             int index = ui->checkTravcomboBox->currentIndex() - 1;
             travelerIndex = index;
            //设置预计到达目的地时间、计划展示
            traveler temp(travelerList[static_cast<size_t>(index)]);
            ui->expArriveTime->setText(temp.oneRoute.back().arrivalTime.toString());

            QStandardItemModel *model = new QStandardItemModel(ui->tablePlanView);

            model->setColumnCount(5);
            model->setHeaderData(0,Qt::Horizontal,"交通");
            model->setHeaderData(1,Qt::Horizontal,"起点");
            model->setHeaderData(2,Qt::Horizontal,"终点");
            model->setHeaderData(3,Qt::Horizontal,"出发时间");
            model->setHeaderData(4,Qt::Horizontal,"到达时间");
            ui->tablePlanView->setModel(model);
            ui->tablePlanView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);

            for(size_t i = 0; i < travelerList[static_cast<size_t>(index)].oneRoute.size(); ++i)
            {
                QStandardItem* vehicle = new QStandardItem(QString::fromStdString
                                                         (transSchedule::vehicleList[static_cast<size_t>(temp.oneRoute[i].vehicle)]));
                QStandardItem* start = new QStandardItem(QString::
                                                         fromStdString(transSchedule::cityList[static_cast<size_t>(temp.oneRoute[i].depatureStation)]));
                QStandardItem* end = new QStandardItem(QString::
                                                         fromStdString(transSchedule::cityList[static_cast<size_t>(temp.oneRoute[i].terminalStation)]));
                QStandardItem* endTime = new QStandardItem(temp.oneRoute[i].arrivalTime.toString());

                QStandardItem* beginTime = new QStandardItem(temp.oneRoute[i].leavingTime.toString());

//                vehicle->setTextAlignment(Qt::AlignBottom);
//                start->setTextAlignment(Qt::AlignVCenter);
//                end->setTextAlignment(Qt::AlignVCenter);
//                endTime->setTextAlignment(Qt::AlignVCenter);

                vehicle->setTextAlignment(Qt::AlignCenter);
                start->setTextAlignment(Qt::AlignCenter);
                end->setTextAlignment(Qt::AlignCenter);
                endTime->setTextAlignment(Qt::AlignCenter);
                beginTime->setTextAlignment(Qt::AlignCenter);

                vehicle->setEditable(false);
                start->setEditable(false);
                end->setEditable(false);
                endTime->setEditable(false);
                beginTime->setEditable(false);

                model->setItem(static_cast<int>(i), 0, vehicle);
                model->setItem(static_cast<int>(i), 1, start);
                model->setItem(static_cast<int>(i), 2, end);
                model->setItem(static_cast<int>(i), 3, beginTime);
                model->setItem(static_cast<int>(i), 4, endTime);
            }

            QString str = QString("当前乘客起点%1,终点%2").arg
                    (QString::fromStdString(transSchedule::cityList
                                            [static_cast<size_t>(travelerList[static_cast<size_t>(index)]
                                            .oneRoute.front().depatureStation)]))
                    .arg(QString::fromStdString(transSchedule::cityList
                                                [static_cast<size_t>(travelerList[static_cast<size_t>(index)]
                                                .oneRoute.back().terminalStation)]));

           speech->say(str);

        }


    });
}

void MainWindow::setCitySecurityButton()
{
    connect(ui->citysSecurityButton,&QPushButton::pressed,ui->myMap,&chinaMap::dealCitySecurityButton);
}



//更该旅客按钮设置
void MainWindow::setChangeDestButton()
{
    connect(ui->changeDestButton, &QPushButton::clicked,this,&MainWindow::dealChangeButton);
    connect(ui->changeDestButton, SIGNAL(pressed()),masterTimer,SLOT(stop()));
}


void MainWindow::dealChangeButton()
{
    changeDest myDialog(this);
    connect(&myDialog, static_cast<void(changeDest::*)(traveler)>(&changeDest::sendData), this,[=](traveler temp){
           temp.calcPlan();
           size_t index = static_cast<size_t>(travelerIndex);
           travelerList[index].targetStation = temp.targetStation;
           size_t loc = travelerList[index].curRoute;
           travelerList[index].oneRoute.resize(loc + 1);
           travelerList[index].totalRiskValue += temp.totalRiskValue;
           for(size_t i = 0; i < temp.oneRoute.size(); ++i)
           {
               travelerList[index].oneRoute.push_back(temp.oneRoute[i]);
           }

    });


    connect(&myDialog,SIGNAL(accepted()),masterTimer,SLOT(start()));
    connect(&myDialog,SIGNAL(rejected()),masterTimer,SLOT(start()));
    connect(&myDialog,SIGNAL(finished()),masterTimer,SLOT(start()));
    myDialog.setModal(false);
    myDialog.exec();
}


//查询按钮设置
void MainWindow::setLookUpButton()
{
    connect(ui->lookUpButton, &QPushButton::clicked,this,&MainWindow::dealLookUpButton);
    connect(ui->lookUpButton, SIGNAL(pressed()),masterTimer,SLOT(stop()));
}


void MainWindow::dealLookUpButton()
{
    lookUpAllRoutes myDialog(this);


    connect(&myDialog,SIGNAL(accepted()),masterTimer,SLOT(start()));
    connect(&myDialog,SIGNAL(rejected()),masterTimer,SLOT(start()));
    connect(&myDialog,SIGNAL(finished()),masterTimer,SLOT(start()));
    myDialog.setModal(false);
    myDialog.exec();
}


//增加旅客按钮设置
void MainWindow::setAddButton()
{
    //添加旅客按钮
    connect(ui->addTravelerButton,&QPushButton::released,this,&MainWindow::dealAddTravelerButton);
    connect(ui->addTravelerButton,SIGNAL(pressed()),masterTimer,SLOT(stop()));
}

void MainWindow::dealAddTravelerButton()
{
   addTravelerDialog myDialog(this);
   connect(&myDialog, static_cast<void(addTravelerDialog::*)(traveler)>(&addTravelerDialog::sendData), this,[=](traveler temp){
       if(temp.timeLimited != 0)
       {
           temp.calcPlan();
           if(temp.routeSelected == -1)
           {
               qDebug() <<"没有在规定时间内的路线";
               QMessageBox warningBox(this);
               warningBox.setWindowTitle("旅客设定时间不足提示");
               warningBox.setText("没有您规定时间内的路线,请重试");
               warningBox.setDetailedText("无法在您设定的最短时间内完成行程,请重新添加");
               warningBox.exec();
           }
           else
           {
                travelerList.push_back(temp);
                ui->checkTravcomboBox->addItem(QString::number(travelerList.size()));
                ++traveler::totalTravelerNumber;
                qDebug() << "添加乘客成功该旅客的路线是"
                         <<QString::fromStdString(transSchedule::cityList[static_cast<size_t>(temp.startStation)])
                         <<"------"
                         <<QString::fromStdString(transSchedule::cityList[static_cast<size_t>(temp.targetStation)]);
           }
       }
       else
       {
           temp.calcPlan();
           if(temp.routeSelected == -1)
           {
               qDebug() <<"没有这样一条路线";
               QMessageBox warningBox(this);
               warningBox.setWindowTitle("没有这条路线提示");
               warningBox.setText("没有符合条件的路线请重试");
               warningBox.setDetailedText("没有符合的路线");
               warningBox.exec();
           }
           else
           {
               travelerList.push_back(temp);
//               qDebug() << "travelerList大小" << travelerList.size();
               ui->checkTravcomboBox->addItem(QString::number(travelerList.size()));
               ++traveler::totalTravelerNumber;
               qDebug() << "添加乘客成功该旅客的路线是"
                        <<QString::fromStdString(transSchedule::cityList[static_cast<size_t>(temp.startStation)])
                        <<"------"
                        <<QString::fromStdString(transSchedule::cityList[static_cast<size_t>(temp.targetStation)]);
         //      qDebug() <<"乘客信息"<<temp.startStation<<" "<<temp.targetStation<<" "<< temp.strategy;
           }
       }
   });

   connect(&myDialog,SIGNAL(accepted()),masterTimer,SLOT(start()));
   connect(&myDialog,SIGNAL(rejected()),masterTimer,SLOT(start()));
   connect(&myDialog,SIGNAL(finished()),masterTimer,SLOT(start()));
   myDialog.setModal(true);
   myDialog.exec();

}

//按触发增加每位旅客的消耗时间
void MainWindow::dealWithcostedTime()
{
    for(size_t i = 0; i < travelerList.size(); ++i)
    {
        int min = travelerList[i].travelMin;
        int hour = travelerList[i].travelHour;

        travelerList[i].totalMin += 1;
        min += 1;
        hour += min/60;
        min %=60;
        travelerList[i].travelMin = min;
        travelerList[i].travelHour = hour;
        travelerList[i].costedTime = hour;
    }
}

//设置主时钟
void MainWindow::setMasterTimer()
{

    masterTimer = new QTimer();
    masterTimerThread = new QThread();
    masterTimer->moveToThread(masterTimerThread);
    masterTimer->setInterval(timerInterval);

    qDebug()<<"主时钟成功启动";

    connect(masterTimerThread,SIGNAL(started()),masterTimer,SLOT(start()));
    connect(masterTimerThread,&QThread::finished,masterTimer,&QTimer::stop);
    connect(masterTimer,&QTimer::timeout,this,[=](){

        MainWindow::dealWithcostedTime();

        masterTimeMinute += 1;
        masterTimeHour += masterTimeMinute/60;
        masterTimeMinute %= 60;
        masterTimeHour = masterTimeHour % 24;

        QTime tempTime;
        tempTime.setHMS(masterTimeHour,masterTimeMinute,0);
        QString tempStr = tempTime.toString("hh:mm");
        ui->masterTimeLcd->display(tempStr);
        ui->sumOfTravelersLcdNumber->display(QString::number(travelerList.size()));
        ui->statusBar->showMessage("计算机学院|陈萌|学号2018211624|旅行规划");

    },Qt::DirectConnection);
    masterTimerThread->start();
}

//UI界面
void MainWindow::setMytravelPlanUI()
{

    ui->setupUi(this);
    this->setGeometry(QRect(300,70,1400,980));
    this->setWindowTitle("疫情期间低风险旅行策略规划");

    ui->myMap->setFixedSize(1100,900);
    ui->frame->setGeometry(1120,0,380,900);

    ui->masterTimeLcd->setFixedSize(QSize(380,90));

    ui->sumOfTravelersLcdNumber->setFixedSize(QSize(80,30));
    ui->checkTravcomboBox->addItem("请选择");

    ui->expArriveTime->setReadOnly(true);
    ui->expArriveTime->setAlignment(Qt::AlignHCenter);
    ui->tablePlanView->setFixedHeight(300);
    ui->changeDestButton->setEnabled(false);

    ui->statusBar->showMessage("计算机学院|陈萌|学号2018211624|旅行规划");


    QMovie* movie = new QMovie(":/image/movie3.gif");
    ui->movieLabel->setMovie(movie);
    movie->start();
}


MainWindow::~MainWindow()
{
    masterTimerThread->quit();
    delete ui;
}


//接口函数
int MainWindow::getCurTravelerNo()
{
    return ui->checkTravcomboBox->currentIndex() - 1;
}

int MainWindow::getMasterTimeHour()
{
   return masterTimeHour;
}

int MainWindow::getMasterTimeMin()
{
    return masterTimeMinute;
}

void MainWindow::disableChange()
{
    ui->changeDestButton->setEnabled(false);
}
