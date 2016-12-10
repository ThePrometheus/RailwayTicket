#include "station.h"
#include "route.h"
#include <QString>
#include <QDebug>
#include <QVector>
#include <QSharedPointer>

Station::Station(QString name):_station_name(name){

    qDebug()<<"Empty station created"<<endl;


}
Station::~Station(){
    qDebug()<<"Station deleted"<<endl;
}
void Station::addRoute(const QSharedPointer<Route>&  route ){
    _depart_routes.append(route);
}
QString Station::getStationName(){
    return _station_name;
}
//TO-DO:Handle exceptions
const QSharedPointer<Route>& Station::getRoute(int id){
    return _depart_routes[id];
}


