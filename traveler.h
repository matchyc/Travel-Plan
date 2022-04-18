#ifndef TRAVELER_H
#define TRAVELER_H

#include "transschedule.h"
#include <QTime>
#include <vector>
#include <stack>

class traveler
{
public:
    traveler();
    traveler(int start, int end, QTime begin, int costed, int choice);

    void calcPlan();
    void dfs(int n, int dest);
    void st2Dfs(int n, int dest);
    double vehicleRisk(transSchedule::Cschedule route);
    double getRiskValue();
    double getTotalRiskValue();
    int getWaitTime();



    std::stack<int> downPeriodTime;

    static int totalTravelerNumber;

//    int vehicle;
    int startStation;
    int targetStation;

    int timeLimited;
    QTime beginTime;
    int costedTime = 0;

    int strategy;

    double tempVehicleRisk;

    std::vector<transSchedule::Cschedule> oneRoute;//一条线路的记录
    std::vector<std::vector<transSchedule::Cschedule> > possi;//每条可能线路
    std::vector<double> riskValueForAllRoute; //每条可能线路的风险值

    int timeMark = 0; //记录所用时间

    int routeSelected = -1;

    double totalRiskValue = 0;

    //画图有关
    size_t curRoute = 0;
    int travelHour = 0;
    int travelMin = 0;
    int totalMin = 0;

    std::vector<int> passedCity;

    bool isArrival = false;

//    std::vector<std::vector<transSchedule::Cschedule> > st2Possi;


//    bool limitedCheck; //记录目前线路所用的时间是否符合限时策略
//    QTime sumOfTime;

//    int travelPlan;

private:
//    std::vector<transSchedule::Cschedule> plan;
//    std::multimap<int,transSchedule::Cschedule> mp;
    int maxDfsLayer = 8;
    int currentLayer = 0;

};

#endif // TRAVELER_H
