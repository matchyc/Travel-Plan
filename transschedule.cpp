#include "transschedule.h"
#include "chinamap.h"

std::unordered_map<std::string,int> transSchedule::cityName2Number;
std::unordered_map<int,double> transSchedule::cityRiskLevel;
std::map<int,int> transSchedule::vehicleRiskLevel;
std::multimap<int,transSchedule::Cschedule> transSchedule::allRoute;
std::map<std::string,int> transSchedule::vehicle2Number;
std::vector<std::string> transSchedule::cityList;
int transSchedule::max_city_number = 0;
std::vector<std::string> transSchedule::vehicleList;


transSchedule::transSchedule()
{
    vehicleRiskLevel.insert(std::make_pair(1,2));
    vehicleRiskLevel.insert(std::make_pair(2,5));
    vehicleRiskLevel.insert(std::make_pair(3,9));
    vehicle2Number.insert(std::make_pair("汽车",1));
    vehicle2Number.insert(std::make_pair("火车",2));
    vehicle2Number.insert(std::make_pair("飞机",3));

    vehicleList.push_back("占位");
    vehicleList.push_back("汽车");
    vehicleList.push_back("火车");
    vehicleList.push_back("飞机");
    readCityName();
    readData();

    //输出测试的一条路线
//    qDebug() << "这条线的终点"<<it->second.terminalStation;
}

void transSchedule::readCityName()
{
    int index = 0;
    QFile f(":/data/cityname.txt");
    if(!f.open(QIODevice::ReadOnly))
    {
        qDebug() << "打开城市名字文件失败";
        return ;
    }

    QTextStream cf(&f);
    //重要的Codec
    cf.setCodec("utf-8");
    QString cityname, posX, posY;
    double riskLevel;
    while(!cf.atEnd())
    {
        cf >> cityname >> riskLevel  >> posX >> posY;
        if(cityname.size()!= 0)
        {
            cityName2Number.insert(std::make_pair(cityname.toStdString(),index));
            cityRiskLevel[index] = riskLevel;
//            qDebug() << cityname << riskLevel << posX << posY;
            cityList.push_back(cityname.toStdString());
            chinaMap::citiesPosition.push_back(std::make_pair(posX.toInt(),posY.toInt()));
            ++max_city_number;
            ++index;

        }
    }
    f.close();
}

void transSchedule::readData()
{
    QFile fs(":/data/test.txt");

    if(!fs.open(QIODevice::ReadOnly))
    {
        qDebug() << "打开文件失败";
        exit(0);
    }

    QTextStream ifs(&fs);
    //codec
    ifs.setCodec("utf-8");
    QString src,des,beginTime,endTime, carrier;

    while(!ifs.atEnd())
    {
        ifs >> src >> des >> beginTime >> endTime >> carrier;
        if(src.size() != 0)
        {
            Cschedule aRoute(cityName2Number[src.toStdString()],cityName2Number[des.toStdString()],QTime::fromString(beginTime)
                             ,QTime::fromString(endTime),vehicle2Number[carrier.toStdString()]);
//            qDebug() << aRoute.depatureStation <<"aaaa"<< aRoute.terminalStation;
            std::pair<int,Cschedule> p = std::make_pair(cityName2Number[src.toStdString()],aRoute);
//            qDebug() << p.first << QString::fromStdString(cityList[p.first]) << aRoute.depatureStation;
            allRoute.insert(p);
//            allRoute.insert(std::make_pair(cityName2Number[src.toStdString()],aRoute));
//            qDebug() << "北京的标号" << cityName2Number["北京"];
//            qDebug() << "+++"<<src<<" "<<des<<" "<<carrier;
//            qDebug() << QString::fromStdString(cityList[allRoute.rbegin()->second.depatureStation]) <<"----" << QString::fromStdString(cityList[allRoute.rbegin()->second.terminalStation]);
        }

    }
//    for(auto it = allRoute.begin(); it != allRoute.end(); ++it)
//    {
//        qDebug() << it->second.depatureStation << "---" << it->second.terminalStation;
//    }
    fs.close();
}

transSchedule::Cschedule::Cschedule(int a, int b, QTime begin, QTime end, int carrier)
    :depatureStation(a),terminalStation(b),leavingTime(begin),arrivalTime(end),vehicle(carrier),limitedCheck(true)
{
    int s = leavingTime.hour();
    int e = arrivalTime.hour();

    if(e > s)
        period = e - s;
    else if(e <= s)
        period = 24 + e - s;
}

transSchedule::Cschedule::Cschedule()
{


}
