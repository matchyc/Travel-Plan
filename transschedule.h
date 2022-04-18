#ifndef TRANSSCHEDULE_H
#define TRANSSCHEDULE_H
#include <map>
#include <unordered_map>
#include <QString>
#include <algorithm>
#include <QFile>
#include <QDebug>
#include <QTime>
#include <string>
#include <vector>

class transSchedule
{

public:
    transSchedule();

    void readData();
    void readCityName();

    static std::unordered_map<std::string,int> cityName2Number;
    static std::vector<std::string> cityList;
    static std::unordered_map<int,double> cityRiskLevel;
    static std::map<int,int> vehicleRiskLevel;
    static std::map<std::string,int> vehicle2Number;
    static std::vector<std::string> vehicleList;
    static int max_city_number;

    class Cschedule{
    public:
        Cschedule(int a, int b, QTime begin, QTime end, int carrier);
        Cschedule();
        int depatureStation;
        int terminalStation;
        QTime leavingTime;
        QTime arrivalTime;
        int period;
        int vehicle;
        bool limitedCheck;
    //    int transNumber;

    };

    static std::multimap<int,Cschedule> allRoute;

};

#endif // TRANSSCHEDULE_H
