#include "traveler.h"
#include <queue>
#include <vector>
#include <algorithm>


int traveler::totalTravelerNumber = 0;
//const int max_city = 10;//transSchedule::max_city_number;
traveler::traveler()
{


}


traveler::traveler(int start, int end, QTime begin, int costed, int choice)
    :startStation(start),targetStation(end),timeLimited(0),beginTime(begin)
    ,costedTime(costed),strategy(choice),tempVehicleRisk(0.0)
{
//    ++totalTravelerNumber;

//    calcPlan();
}



void traveler::calcPlan()
{
//    qDebug() << "调用了一次计算路径函数";
    if(strategy == 0)
    {
//        qDebug() <<"乘客信息"<<startStation<<" "<<targetStation<<" "<< strategy;

        //起点入栈
        passedCity.push_back(startStation);

         dfs(startStation, targetStation);
//         qDebug() << "算完策略1的dfs" ;
         currentLayer = 0;
         int minRiskRoute = -1;
         double minRisk = 999999;

         if(riskValueForAllRoute.size() > 0)
         {

//             qDebug() << "进入找最小风险之前";
             for(size_t i = 0; i < riskValueForAllRoute.size(); ++i)
             {
//                 qDebug() << "进入找最小风险";
                 if(minRisk > riskValueForAllRoute[i])
                 {
                     minRiskRoute = static_cast<int>(i);
                     minRisk = riskValueForAllRoute[i];
                     totalRiskValue = minRisk;
                 }
             }
             //打印路线
//             for(size_t i = 0; i < possi[(size_t)minRiskRoute].size(); ++i)
//             {
//                 qDebug() << QString::fromStdString(transSchedule::cityList[static_cast<size_t>(possi[minRiskRoute][i].depatureStation)])<<"--" <<
//                        QString::fromStdString(transSchedule::cityList[static_cast<size_t>(possi[minRiskRoute][i].terminalStation)]);
//             }
              oneRoute = possi[static_cast<size_t>(minRiskRoute)];
         }

         routeSelected = minRiskRoute;

    }

    else if( strategy == 1)
    {
        //起点入栈
        passedCity.push_back(startStation);

//        qDebug() << "开始计算策略2";
        st2Dfs(startStation, targetStation);
//        qDebug() << "算完策略2的dfs";
        currentLayer = 0;
        int minRiskRoute = -1;

        if(riskValueForAllRoute.size()>0)
        {
            qDebug() << "找到" << riskValueForAllRoute.size() << "条符合时间限制的路线";
            double minRisk = riskValueForAllRoute.front();
            minRiskRoute = 0;
            for(size_t i = 0; i < riskValueForAllRoute.size(); ++i)
            {
//                qDebug() << "限时完成后，进入最小风险的查找";
                if(minRisk > riskValueForAllRoute[i])
                {
                    minRiskRoute = static_cast<int>(i);
                    minRisk = riskValueForAllRoute[i];
                    totalRiskValue = minRisk;
                }
            }
             oneRoute = possi[static_cast<size_t>(minRiskRoute)];
        }
        else
        {
            qDebug() << "没有找到符合时间限制的路线";
        }

        routeSelected = minRiskRoute;

//        qDebug() << "选择的路线" << routeSelected;
        //之后准备在所有可能路线中找 limitercheck == true的 然后在里面选最小的

    }
    qDebug() <<"计算路径完成";
    while(!downPeriodTime.empty())
    {
        downPeriodTime.pop();
    }
}

//计算一个班次的交通工具风险
double traveler::vehicleRisk(transSchedule::Cschedule route)
{
    return route.period * transSchedule::vehicleRiskLevel[route.vehicle] *
            transSchedule::cityRiskLevel[route.depatureStation];
}


//计算当前可能线路的城市风险值
double traveler::getRiskValue()
{
    auto preit = oneRoute.begin();
    auto curit = oneRoute.begin();
    ++curit;
    double sumRisk = 0.0;
    for(;curit != oneRoute.end(); ++curit, ++preit)
    {
        int s = preit->arrivalTime.hour();
        int e = curit->leavingTime.hour();
        int period = 0;
        if(e > s)
            period = e - s;
        else
            period = e - s + 24;

        sumRisk += transSchedule::cityRiskLevel[preit->terminalStation] * period;
    }

    return sumRisk;
}

//计算当前路线的在中途城市的等待时间
int traveler::getWaitTime()
{
    auto preit = oneRoute.begin();
    auto curit = oneRoute.begin();
    ++curit;
    int sumTime = 0;
    int tempWaitTime = 0;
    tempWaitTime = preit->leavingTime.hour() - beginTime.hour();
    if(tempWaitTime <= 0)
    {
        tempWaitTime += 24;
    }
//    qDebug() << "初始等待时间" << tempWaitTime;
    sumTime += tempWaitTime;
    for(;curit != oneRoute.end(); ++curit, ++preit)
    {
        int s = preit->arrivalTime.hour();
        int e = curit->leavingTime.hour();
        int period = 0;
        if(e > s)
            period = e - s;
        else
            period = e - s + 24;

//        qDebug() << "这段等待时间" << period;
        sumTime += period;
//        qDebug() << "每次累加等待时间" << sumTime;
    }

    return sumTime;
}

void traveler::st2Dfs(int n, int dest)
{

    if( n == dest || currentLayer >= maxDfsLayer)
    {
        if(oneRoute.front().depatureStation == startStation && oneRoute.back().terminalStation == targetStation)
        {
            if(timeMark + getWaitTime() <= timeLimited)//加入时间判断
            {
//                qDebug() << "策略2,这条路线符合条件";
                oneRoute.front().limitedCheck = true;
                possi.push_back(oneRoute);
                riskValueForAllRoute.push_back(tempVehicleRisk + getRiskValue());
            }
            else
            {
//                qDebug() <<"这不符合时间限制的路线所要消耗的时间是" << "过程时间" << timeMark << "等待出发时间" << getWaitTime();
                oneRoute.front().limitedCheck = false;
            }
        }
        oneRoute.clear();
        passedCity.clear();
        passedCity.push_back(startStation);
        timeMark = 0;
        tempVehicleRisk = 0.0;
        return;
    }

    ++currentLayer;

//    qDebug() <<"当前起点" << n << "最终目的地" << dest;
    auto iter = transSchedule::allRoute.find(n);
//    qDebug() << "进入策略2的dfs";
//    qDebug() <<iter->first<<" "<<n;
    for(;iter != transSchedule::allRoute.end() && iter->first == n; ++iter)
    {
//        qDebug() <<iter->first<<" "<<n;
//        qDebug() << "搜一条";
        if(std::find(passedCity.begin(),passedCity.end(),iter->second.terminalStation) == passedCity.end())
        {
//            qDebug() << "终点不是这条路线上曾经经过的城市,可以继续搜索...";
            tempVehicleRisk += vehicleRisk(iter->second);
            timeMark += iter->second.period;
            passedCity.push_back(iter->second.terminalStation);
            downPeriodTime.push(iter->second.period);
            oneRoute.push_back(iter->second);
//            qDebug() << "这条线的终点" << iter->second.terminalStation;
            st2Dfs(iter->second.terminalStation,dest);
        }
        else
        {
//             qDebug() << "是已经经过的城市,搜索一下条";
        }

    }
//    qDebug() <<"返回";
    if(!downPeriodTime.empty())
    {
        timeMark -= downPeriodTime.top();
        downPeriodTime.pop();
        if(oneRoute.size() != 0)
        oneRoute.pop_back();
    }

}

void traveler::dfs(int n, int dest)
{

    if(n == dest || currentLayer >= maxDfsLayer)
    {
//        qDebug() << "搜到终点";
        if(oneRoute.front().depatureStation == startStation && oneRoute.back().terminalStation == targetStation)
        {
            possi.push_back(oneRoute);
            riskValueForAllRoute.push_back(tempVehicleRisk);
            *riskValueForAllRoute.rbegin() += getRiskValue();
        }
        oneRoute.clear();
        tempVehicleRisk = 0.0;
        passedCity.clear();
        passedCity.push_back(startStation);
        return;
    }

    auto iter = transSchedule::allRoute.find(n);
//    qDebug() << "进入dfs";
    ++currentLayer;
    for(;iter != transSchedule::allRoute.end() && iter->first == n; ++iter)
    {
//        qDebug() << "搜一条";

        //如果没有经历过，就搜它
        if(std::find(passedCity.begin(),passedCity.end(),iter->second.terminalStation) == passedCity.end())
        {
//            qDebug() << "终点不是这条路线上曾经经过的城市,可以继续搜索...";
            tempVehicleRisk += vehicleRisk(iter->second);
            oneRoute.push_back(iter->second);
            passedCity.push_back(iter->second.terminalStation);
//            qDebug() << "这条线的终点" << iter->second.terminalStation;
            dfs(iter->second.terminalStation,dest);
        }
        else
        {
//            qDebug() << "是已经经过的城市,搜索一下条";
        }
    }

    if(oneRoute.size() != 0)
         oneRoute.pop_back();
}


double traveler::getTotalRiskValue()
{
    totalRiskValue = 0;
    for( size_t i = 0; i < oneRoute.size(); ++i)
    {
        totalRiskValue += vehicleRisk(oneRoute[i]);
    }
    totalRiskValue += getRiskValue();
    return totalRiskValue;
}

