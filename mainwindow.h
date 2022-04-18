#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "transschedule.h"
#include "traveler.h"
#include "addtravelerdialog.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QTime>
#include <QWidget>
#include <QMainWindow>
#include <vector>
#include <QtTextToSpeech/QTextToSpeech>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); //构造函数
    ~MainWindow();              //析构函数

    void setMytravelPlanUI();   //设置MainWindow的UI界面
    void setMasterTimer();      //设置主定时器
    void setAddButton();        //设置添加旅客按钮
    void setInquireComboBox();      //设置选择查看旅客的下拉框
    void setLookUpButton();         //设置查询按钮
    void setChangeDestButton();     //设置改变目的地按钮
    void setCitySecurityButton();   //设置查询城市风险等级按钮

    void dealChangeButton();        //处理改变目的地按钮点击时间
    void dealAddTravelerButton();   //应对添加旅客按钮的点击事件
    void dealWithcostedTime();      //跟进每一位旅客的行程时间
    void dealLookUpButton();        //处理查询路线按钮点击事件

    int getCurTravelerNo();         //接口函数，供外界调用得到当前查看、绘制的旅客
    int getMasterTimeHour();        //接口函数，供外界调用得到masterTimeHour
    int getMasterTimeMin();         //接口函数，供外界调用得到masterTimeMin
    void disableChange();           //接口函数，供外界将changeDest按钮置为不可用

    transSchedule officialSchedule;
    std::vector<traveler> travelerList;

    int masterTimeHour = 0;
    int masterTimeMinute = 0;
    static int travelerIndex;
    static int timerInterval;

    QTextToSpeech* speech;
protected:


private:
    Ui::MainWindow *ui;
        QTimer* masterTimer;
        QThread* masterTimerThread;

signals:
        void startTimer();
};

#endif // MAINWINDOW_H
