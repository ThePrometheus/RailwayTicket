#include <QVector>
#include <QSharedPointer>
#include "station.h"
#include "bahn.h"
 Bahn::Bahn(){
 qDebug()<<"Bahn is created"<<endl;
}
 Bahn::~Bahn(){
     qDebug()<<"Bahn is deleted"<<endl;

 }
 //TO-DO:Optimize query
 const QSharedPointer<Station>& Bahn:: findDepartStation(QString query){
for(int i=0;i<_stations.size();++i){
 if(_stations.at(i)->getStationName()==query){
 return _stations.at(i);
 }
 }
 }
void Bahn::addStation( Station * s){
    _stations.append(QSharedPointer<Station> (s));

}


