#ifndef ROUTE_H
#define ROUTE_H
#include <QString>
#include "train.h"
#include <QVector>
#include <QSharedPointer>
#include "stops.h"
#include <QJsonObject>
class Route {
private:
    QString _depart_station;
    int _route_id;
    QVector<Train>* _trains;
    int _nstops;
    QVector<Stops>* _stops;
    int _route_size;
public:
    void populateRoute();
    void depopulateRoute();

    Route(const QString& depart_station="NA", int id=0, int route_size=0);
    Route(const Route&);
    Route&operator=(const Route&);
    ~Route();
    const QSharedPointer<Train>& findByDate(int date) const;
    const QString& getDepartStation() const;
    const QVector<QString> getArrivalStations() const;
    const int getId() const{return _route_id;}
    //const QVector<QSharedPointer<Stops>>& getStops() const {return _stops;}
    const int getRouteSize() const {return _route_size;}

    // JSON read/write
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    const QString& getStationAt(int date);
    void addArrivalStation(int date, QString station);

    void bookSeat(int date, int train, int wagon, int seat) const;

};

bool operator ==(const Route& r1, const Route& r2);

#endif // ROUTE_H
