#include <QString>
#include "stops.h"
#include <QDebug>

Stops::Stops(int date,QString station):_date(date),_station(station){
#ifndef QT_NO_DEBUG
    qDebug()<<"New stop is created"<<endl;
#endif

}
Stops::~Stops(){
#ifndef QT_NO_DEBUG
    qDebug()<<" stop is deleted"<<endl;
#endif

}
Stops::Stops (const Stops& s ){
     Stops(s.getDate(),s.getStation());

}


void Stops::read(const QJsonObject &json) {
    _date = json["date"].toInt();
    _station = json["station"].toString();
}

void Stops::write(QJsonObject &json) {
    json["date"] = this->_date;
    json["station"] = this->_station;
}
