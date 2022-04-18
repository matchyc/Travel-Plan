#include "chinamap.h"
#include "ui_chinamap.h"
#include "mainwindow.h"
#include <QPainter>
#include <QFont>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>
#include <cmath>


std::vector<std::pair<int,int> > chinaMap::citiesPosition;


chinaMap::chinaMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chinaMap)
{
    ui->setupUi(this);
    //两重转换，使fa指向主窗口mainwindow
    fa = static_cast<MainWindow*>(parentWidget());
    fa = static_cast<MainWindow*>(fa->parentWidget());
    //设置调色板，把地图作为背景图绘制
//    qDebug() << "travelerList大小" << fa->travelerList.size();
    QPalette myPalette(this->palette());
    setMyChinaMap(myPalette);
    setClockForPaint();

    connect(fa,SIGNAL(startTimer),paintTimer,SLOT(start()));
}

void chinaMap::dealCitySecurityButton()
{
    qDebug() << "点击了显示城市风险等级";
    showCityRiskLevel = !showCityRiskLevel;
    update();
}
QPainterPath chinaMap::getCurRoutePath()
{
    int index = MainWindow::travelerIndex;
    traveler temp = fa->travelerList[static_cast<size_t>(index)];
    QPointF beginPos(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[0].depatureStation)].first,
            chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[0].depatureStation)].second);

    QPainterPath path(beginPos);

    for(size_t i = 0; i < temp.oneRoute.size(); ++i)
    {
        QPointF tempEnd(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[i].terminalStation)].first,
                chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[i].terminalStation)].second);
        path.lineTo(tempEnd);
    }

    return path;
}

QPointF chinaMap::getPicturePos()
{
//    qDebug() << "进入picture位置的计算";
    int index = MainWindow::travelerIndex;
    traveler temp = fa->travelerList[static_cast<size_t>(index)];

    QPointF beginPos(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].depatureStation)].first,
            chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].depatureStation)].second);

    QPointF endPos(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].terminalStation)].first,
            chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].terminalStation)].second);

    //min为单位
    int midTime = temp.oneRoute[temp.curRoute].period;
    midTime = midTime * 60;

    //计算几何数值
    double distance = sqrt((beginPos.x() - endPos.x())*(beginPos.x() - endPos.x()) +
                           (beginPos.y() - endPos.y())*(beginPos.y() - endPos.y()));
    double sinAlpha = fabs((beginPos.y() - endPos.y())) / distance;
    double cosAlpha = fabs((beginPos.x() - endPos.x())) / distance;

    double incDistance = distance / midTime;

    double incX = 0, incY = 0;

    //若起点在终点上方
    if((beginPos.y() - endPos.y()) < 0)
    {
        incX = incDistance * cosAlpha;
        if((beginPos.x() - endPos.x()) > 0)
        {
            incX *= -1;
        }
        incY = incDistance * sinAlpha;
    }

    else
    {
        incX = incDistance * cosAlpha;
        if((beginPos.x() - endPos.x()) > 0)
        {
            incX *= -1;
        }
        incY = incDistance * sinAlpha * -1;
    }



    int curRouteNeedTime = 0;
    curRouteNeedTime = temp.oneRoute[temp.curRoute].arrivalTime.hour() - temp.beginTime.hour();
    if(curRouteNeedTime <= 0)
        curRouteNeedTime += 24;

    int waitedTime = 0;
    waitedTime = temp.oneRoute[temp.curRoute].leavingTime.hour() - temp.beginTime.hour();
    if(waitedTime <= 0)
    {
        waitedTime += 24;
    }


    incX *= temp.totalMin - waitedTime * 60;
    incY *= temp.totalMin - waitedTime * 60;


    double fixPicPos = 27.5;
    //未发车状态
    if( temp.costedTime < waitedTime)
    {
        return QPointF(beginPos.x() - fixPicPos, beginPos.y() - fixPicPos);
    }
    //发车状态
    else if(temp.costedTime >= waitedTime)
    {
        return  QPointF(beginPos.x() - fixPicPos+ incX, beginPos.y() + incY - fixPicPos);
    }

    //任意返回一个值
    return QPointF(1,1);
}

std::pair<QPointF,QPointF> chinaMap::getPairLocation()
{
//    qDebug() << "进入两端点的计算";
    int index = MainWindow::travelerIndex;
    traveler temp = fa->travelerList[static_cast<size_t>(index)];

    //计算当前班次所需要的时间 两种情况
    curRouteNeedTime = 0;

    //旅客开始时间与出发行程跨天
    if(temp.oneRoute[temp.curRoute].leavingTime.hour() <= temp.beginTime.hour())
    {
        curRouteNeedTime += temp.oneRoute[temp.curRoute].leavingTime.hour() -
                temp.beginTime.hour() + 24;
    }
    //不跨天
    else
    {
        curRouteNeedTime += temp.oneRoute[temp.curRoute].leavingTime.hour() -
                temp.beginTime.hour();
    }
    curRouteNeedTime += temp.oneRoute[temp.curRoute].period;


//    qDebug() << "现在的路线是" << temp.curRoute;
    //等待中
    if(curRouteNeedTime - temp.costedTime <= 0)
    {
        qDebug() << index <<"号乘客已到达"<<QString::fromStdString(transSchedule::cityList
                                                      [static_cast<size_t>(temp.oneRoute[temp.curRoute].terminalStation)])
                                  <<"进入下一条路线";
        temp.curRoute += 1;
        fa->travelerList[static_cast<size_t>(index)].curRoute = temp.curRoute;
        fa->travelerList[static_cast<size_t>(index)].beginTime.setHMS(fa->getMasterTimeHour(),fa->getMasterTimeMin(),0);
        fa->travelerList[static_cast<size_t>(index)].costedTime = 0;
        fa->travelerList[static_cast<size_t>(index)].travelHour = 0;
        fa->travelerList[static_cast<size_t>(index)].travelMin = fa->getMasterTimeMin();
        fa->travelerList[static_cast<size_t>(index)].totalMin = fa->getMasterTimeMin();
    }
    //运行中
    if(temp.curRoute < temp.oneRoute.size())
    {
        QPointF beginPos(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].depatureStation)].first,
                chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].depatureStation)].second);

        QPointF endPos(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].terminalStation)].first,
                chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute].terminalStation)].second);

        return std::make_pair(beginPos,endPos);
    }
    else {

        QPointF beginPos(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute - 1].depatureStation)].first,
                chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute - 1].depatureStation)].second);

        QPointF endPos(chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute - 1].terminalStation)].first,
                chinaMap::citiesPosition[static_cast<size_t>(temp.oneRoute[temp.curRoute - 1].terminalStation)].second);

        return std::make_pair(beginPos,endPos);
    }
}

QPixmap chinaMap::getVehiclePic()
{
    int index = MainWindow::travelerIndex;
    traveler temp = fa->travelerList[static_cast<size_t>(index)];

    switch(temp.oneRoute[temp.curRoute].vehicle)
    {
    case 1:
        return QPixmap(":/image/car.png");

    case 2:
        return QPixmap(":/image/train.png");

    case 3:
        return QPixmap(":/image/fighter.png");
    }

    //无效返回 防止报错
    return QPixmap(":/image/plane.png");
}

//工具
void chinaMap::mousePressEvent(QMouseEvent *event)
{
    ui->myLabel->setText(QString("位置(%1,%2)").arg(event->x()).arg(event->y()));
}

void chinaMap::setClockForPaint()
{
    paintTimer = new QTimer(this);
    paintTimer->setInterval(1000/6);

//    qDebug()<<"set paint Timer successful";
    connect(paintTimer,&QTimer::timeout,this,[=](){
           if(MainWindow::travelerIndex != -1)
           {
               update();
//               qDebug() << "刷新了mapwidget";
               QString str = QString("当前旅客总风险：%1").arg
                       (fa->travelerList[static_cast<size_t>(fa->travelerIndex)].getTotalRiskValue());

               ui->riskValueLabel->setText(str);
           }

    });
    paintTimer->start();
}

chinaMap::~chinaMap()
{
    delete ui;
}

void chinaMap::paintEvent(QPaintEvent *)
{
//    qDebug() << "进入了paintEvent";
    QPainter p(this);
    QPen penForRoute(Qt::red,5,Qt::SolidLine);
    QPen penForPath(Qt::black,3,Qt::DashDotLine);
    QBrush pBrush(5);
    QPen penForCity(pBrush,5);

    //画城市风险等级
    if(showCityRiskLevel)
    {

        p.setPen(penForCity);
        size_t i = 0;
        int j = 0;
        for( i = 0; i < transSchedule::cityList.size(); ++i)
        {
            j = static_cast<int>(i);
            if(transSchedule::cityRiskLevel[j] > 0.5)
            {
//                qDebug() <<"画高";
                pBrush.setColor(Qt::red);
                penForCity.setBrush(pBrush);
                p.setPen(penForCity);
                p.drawEllipse(QPointF(citiesPosition[i].first,citiesPosition[i].second),5,5);
            }
            else if(transSchedule::cityRiskLevel[j] < 0.5)
            {
//                qDebug() <<"画低";
                pBrush.setColor(Qt::green);
                penForCity.setBrush(pBrush);
                p.setPen(penForCity);
                p.drawEllipse(QPointF(citiesPosition[i].first,citiesPosition[i].second),5,5);
            }
            else
            {
                pBrush.setColor(Qt::blue);
                penForCity.setBrush(pBrush);
                p.setPen(penForCity);
                p.drawEllipse(QPointF(citiesPosition[i].first,citiesPosition[i].second),5,5);
            }
        }
    }

    //不是“请选择”选项，就画地图。
    if(MainWindow::travelerIndex != -1)
    {
        //画路径
        p.setPen(penForPath);
        p.drawPath(getCurRoutePath());

        //画正在进行路径和交通工具图片
        if(fa->travelerList[static_cast<size_t>(MainWindow::travelerIndex)].oneRoute.size()
                > fa->travelerList[static_cast<size_t>(MainWindow::travelerIndex)].curRoute)//如果当前路线没走完，接着画
        {
//            qDebug() << "要在地图上画线了" ;
            p.setPen(penForRoute);
            std::pair<QPointF,QPointF> posPair = getPairLocation();
            p.drawLine(posPair.first,posPair.second);

            if(fa->travelerList[static_cast<size_t>(MainWindow::travelerIndex)].oneRoute.size()
                    > fa->travelerList[static_cast<size_t>(MainWindow::travelerIndex)].curRoute)
                 p.drawPixmap(getPicturePos(),getVehiclePic());

        }
        else
        {

            fa->disableChange();
            if(fa->travelerList[static_cast<size_t>(MainWindow::travelerIndex)].isArrival == false)
            {
                fa->travelerList[static_cast<size_t>(MainWindow::travelerIndex)].isArrival = true;
                qDebug() << MainWindow::travelerIndex << "号乘客已到达目的地";
            }
        }
    }

}

void chinaMap::setMyChinaMap(QPalette& p)
{
    setAutoFillBackground(true);
    QPixmap map(":/image/chinaMap.jpg");
    p.setBrush(QPalette::Window,QBrush(map.scaled(1100,900,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(p);

    ui->riskValueLabel->setGeometry(405,20,350,150);
//    ui->riskValueLabel->setFixedSize(150,300);
    ui->riskValueLabel->setText("当前暂未选中旅客");
    ui->myLabel->setGeometry(70,70,150,100);
    ui->myLabel->setAlignment(Qt::AlignCenter);
    ui->myLabel->setText("辅助管理员定位");

    ui->riskValueLabel->setFont(QFont("华文楷体",20));
    qDebug() << "地图设置完成" ;
}
