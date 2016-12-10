#include <QString>
#include <QSharedPointer>
#include <QVector>
#include "train.h"
#include "route.h"
#include <QDebug>

Route::Route( const QString& depart_station,int id,int route_size,QVector<QSharedPointer<Stops>>& stops):_route_id(id),
    _nstops(stops.size()),_route_size(route_size),_stops(stops),_depart_station(depart_station){
    populateRoute(route_size);

    qDebug()<<"ROUTE IS CREATED"<<endl;



}
Route::~Route(){
    depopulateRoute();

    qDebug()<<"ROUTE IS DELETED"<<endl;

}

void Route::populateRoute(int number){
    _trains = QVector<QSharedPointer<Train>>(number);
    for(int i=0;i<number;++i){
        _trains[i] = QSharedPointer<Train>(new Train(i));
    }
}

void Route::depopulateRoute(){
    for(int i=0;i<_trains.size();++i){
        _trains.at(i)->~Train();
    }
    _trains.clear();
}

const QString& Route::getDepartStation(){
    return _depart_station;
}
const QVector<QString>& Route::getArrivalStations(){
    QVector<QString> temp(_stops.size());
    for(int i=0;i<_stops.size();++i){
        temp[i] = _stops[i]->getStation();

    }
    return QVector<QString>(temp);
}


const QString& Route::getStationAt(int date){
    for(int i=0;i<_stops.size();++i){
        if(_stops[i]->getDate()==date){
            return _stops[i]->getStation();
        }

        //TO-DO::HANDLE SITUATION WHEN NOT FOUND
    }

}
const QSharedPointer<Train>& Route::findByDate(int date){
    for(int i=0;i<_trains.size();++i){
        if(_trains[i]->getDate()==date){
            return _trains[i];
        }

        //TO-DO::HANDLE SITUATION WHEN NOT FOUND
    }
}

//TO-DO::HANDLE EXCEPTION !!!
void Route::addArrivalStation(int date,QString station){
    Stops s(date,station);
    _stops.append(QSharedPointer<Stops>(&s));
    ++_nstops;


}


void Route::read(const QJsonObject &json) {
    _depart_station = json["departStation"].toString();
    _route_id = json["routeId"].toInt();
    _nstops = json["nStops"].toInt();
    _route_size = json["routeSize"].toInt();
    QVector<QSharedPointer<Train>> _trains;
    QVector<QSharedPointer<Stops>> _stops;
}

void Route::write(QJsonObject &json);

