#include <QString>
#include "stops.h"
#include <QDebug>

Stops::Stops(int date,QString station):_date(date),_station(station){
#ifndef QT_NO_DEBUG
    //qDebug()<<"New stop is created"<<endl;
#endif

}
Stops::~Stops(){
#ifndef QT_NO_DEBUG
   // qDebug()<<" stop is deleted"<<endl;
#endif

}
Stops::Stops (const Stops& s ){
     Stops(s.getDate(),s.getStation());

}
Stops& Stops::operator=(const Stops& other) {
    if (this==&other)
        return *this;
    this->_date = other.getDate();
    this->_station = other.getStation();
}


void Stops::read(const QJsonObject &json) {
    _date = json["date"].toInt();
    _station = json["station"].toString();
}

void Stops::write(QJsonObject &json) const {
    json["date"] = (_date) ? this->_date : 0;
    qDebug()<<"hi"<<endl;
    json["station"] = (_station != QString::null) ? this->_station : QString("NA");
}
