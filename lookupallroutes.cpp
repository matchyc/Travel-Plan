#include "lookupallroutes.h"
#include "ui_lookupallroutes.h"
#include "transschedule.h"
#include <QStandardItemModel>


lookUpAllRoutes::lookUpAllRoutes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lookUpAllRoutes)
{
    setUI();

    //信号与槽
    connect(ui->srcComboBox,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,&lookUpAllRoutes::dealIndexChange);
    connect(ui->destComboBox,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,&lookUpAllRoutes::dealIndexChange);

}

lookUpAllRoutes::~lookUpAllRoutes()
{
    delete ui;
}


//与主界面展示类似
void lookUpAllRoutes::dealIndexChange()
{
   int srcIndex = ui->srcComboBox->currentIndex();
   int destIndex = ui->destComboBox->currentIndex();

//   qDebug() << "线路展示";
   //线路展示
   
   QStandardItemModel *model = new QStandardItemModel(ui->planDisplayView);

   model->setColumnCount(5);
   model->setHeaderData(0,Qt::Horizontal,"交通");
   model->setHeaderData(1,Qt::Horizontal,"起点");
   model->setHeaderData(2,Qt::Horizontal,"终点");
   model->setHeaderData(3,Qt::Horizontal,"出发时间");
   model->setHeaderData(4,Qt::Horizontal,"到达时间");
   ui->planDisplayView->setModel(model);

   ui->planDisplayView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

   auto iter = transSchedule::allRoute.begin();

   for (size_t i = 0; iter != transSchedule::allRoute.end(); ++iter)
   {
       if(iter->second.depatureStation == srcIndex && iter->second.terminalStation == destIndex)
       {

           QStandardItem* vehicle = new QStandardItem(QString::fromStdString
                                                      (transSchedule::vehicleList[static_cast<size_t>(iter->second.vehicle)]));

           QStandardItem* start = new QStandardItem(QString::
                                                    fromStdString(transSchedule::cityList[static_cast<size_t>(iter->second.depatureStation)]));
           QStandardItem* end = new QStandardItem(QString::
                                                    fromStdString(transSchedule::cityList[static_cast<size_t>(iter->second.terminalStation)]));
           QStandardItem* endTime = new QStandardItem(iter->second.arrivalTime.toString());

           QStandardItem* beginTime = new QStandardItem(iter->second.leavingTime.toString());


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
           ++i;

       }
   }

}

void lookUpAllRoutes::setUI()
{
    ui->setupUi(this);

    this->setWindowTitle("查询路线窗口");

    int n = transSchedule::max_city_number;
    auto it = transSchedule::cityList.begin();

    for(int i = 0; i < n ; ++i, ++it)
    {
        ui->srcComboBox->addItem(QString::fromStdString(*it));
        ui->destComboBox->addItem(QString::fromStdString(*it));
    }

}
