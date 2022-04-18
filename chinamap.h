#ifndef CHINAMAP_H
#define CHINAMAP_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QBrush>
#include <QPixmap>
#include <QPointF>
#include <QPoint>
#include <vector>
#include "mainwindow.h"

namespace Ui {
class chinaMap;
}

class chinaMap : public QWidget
{
    Q_OBJECT

public:
    explicit chinaMap(QWidget *parent);
    ~chinaMap();
    void setMyChinaMap(QPalette& p);        //设置好我的地图
    void setClockForPaint();           //设置刷新时间
    QPointF getPicturePos();        //得到交通工具的图片位置
    std::pair<QPointF,QPointF> getPairLocation();   //得到当前班次的两个端点位置
    QPainterPath getCurRoutePath();         //得到整条路线
    QPixmap getVehiclePic();                //得到交通工具图片
    void dealCitySecurityButton();          //处理显示城市风险等级的按钮时间

    static std::vector<std::pair<int,int> > citiesPosition;

    int curRouteNeedTime = 0;

    QTimer* paintTimer;
protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent*);


private:
    Ui::chinaMap *ui;

    MainWindow* fa;         //用于调用父窗口的函数
    bool showCityRiskLevel = false; //判断是否显示风险等级
};

#endif // CHINAMAP_H
