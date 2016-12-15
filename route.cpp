#include <QString>
#include <QSharedPointer>
#include <QVector>
#include "train.h"
#include "route.h"
#include <QDebug>
#include <QJsonArray>

Route::Route(const QString& depart_station, int id, int route_size):_route_id(id), _trains(new QVector<Train>),
    _stops(new QVector<Stops>),
    _nstops(0),_route_size(route_size),_depart_station(depart_station){
    //populateRoute(route_size);

    qDebug()<<"ROUTE IS CREATED"<<endl;



}
Route::~Route(){
    depopulateRoute();
   // delete _trains;
  // delete _stops;
    qDebug()<<"ROUTE IS DELETED"<<endl;

}

void Route::populateRoute(){
    for(int i=0;i<_route_size;++i){
        Train t(i+1);
       // qDebug() << t.getId() << " " << t.getDate() << " " << t.getSize();
        _trains->append(t);
        _trains->operator [](i).populateTrain();
        qDebug() << "in populateRoute" << _trains->size();
    }
}

Route::Route(const Route& r) :_route_id(r.getId()),
    _nstops(0),
    _route_size(r.getRouteSize()),
    _stops(new QVector<Stops>),
    _trains(new QVector<Train>),
    _depart_station(r.getDepartStation())
{
 //   populateRoute(_route_size);
}


Route& Route::operator=(const Route& r)
{
    if (this==&r) return *this;
    _route_id = r.getId();
    _nstops = 0;
    _route_size = r.getRouteSize();
    //_stops->clear();
    //_stops = r.getStops();
    _depart_station = r.getDepartStation();
    return *this;
}

bool operator ==(const Route& r1, const Route& r2) {
    return (r1.getId() == r2.getId());
}

void Route::depopulateRoute(){
    qDebug() << "depopulate route";
    for(int i=0;i<_trains->size();++i){
        _trains->at(i).~Train();
    }
    /*for(int i=0;i<_stops->size();++i){
        _stops->at(i).~Stops();
    }*/
    _trains->clear();
    _stops->clear();
}

const QString& Route::getDepartStation() const{
    return _depart_station;
}
const QVector<QString> Route::getArrivalStations() const{
    if (_stops->size() < 0) return QVector<QString>(0);
    QVector<QString> temp;
    for(int i=0;i<_stops->size();++i){
        temp.append(_stops->at(i).getStation());
    }
    return temp;
}


const QString& Route::getStationAt(int date){
    for(int i=0;i<_stops->size();++i){
        if(_stops->at(i).getDate()==date){
            return _stops->at(i).getStation();
        }

        //TO-DO::HANDLE SITUATION WHEN NOT FOUND
    }
    return QString("NA");

}
const QSharedPointer<Train>& Route::findByDate(int date) const{
    qDebug() << "entered findByDate, n of trains: " << _trains->size();
    for(int i=0;i<_trains->size();++i){
        qDebug() << "in findByDate loop";
        if(_trains->at(i).getDate()==date){
            QSharedPointer<Train> ptr(&(_trains->operator [](i)));
            return ptr;
        }

        //TO-DO::HANDLE SITUATION WHEN NOT FOUND
    }
    return QSharedPointer<Train>::create(-1);
}

//TO-DO::HANDLE EXCEPTION !!!
void Route::addArrivalStation(int date,QString station){
    Stops s(date,station);
    _stops->append(s);
    ++_nstops;
}


void Route::read(const QJsonObject &json) {
    qDebug() << "hi";
    _depart_station = json["departStation"].toString();
    _route_id = json["routeId"].toInt();
    _nstops = json["nStops"].toInt();
    _route_size = json["routeSize"].toInt();
    _stops->clear();
    _stops = new QVector<Stops>;
    QJsonArray stops = json["stops"].toArray();
    for (size_t i = 0; i < stops.size(); ++i) {
        Stops s;
        (*_stops).append(s);
    }

    for (size_t i = 0; i < stops.size(); ++i) {
        QJsonObject obj = stops[i].toObject();
        (*_stops).operator [](i).read(obj);
        qDebug() << "C " << (*_stops).at(i).getDate() << (*_stops).at(i).getStation();
    }
}

void Route::write(QJsonObject &json) const {
    json["departStation"] = _depart_station;
    json["routeId"] = _route_id;
    json["nStops"] = _nstops;
    json["routeSize"] = _route_size;
    QJsonArray arr;
    foreach (const Stops& s, *_stops) {
        QJsonObject obj;
        s.write(obj);
        arr.append(obj);
    }
    json["stops"] = arr;
}

