#ifndef ROUTE_H
#define ROUTE_H
#include <QString>
#include "train.h"
#include <QVector>
#include<QSharedPointer>
#include "stops.h"
#include <QJsonObject>
class Route {
private:
    QString _depart_station;
    int _route_id;
    QVector<QSharedPointer<Train>> _trains;
    int _nstops;
    QVector<QSharedPointer<Stops>> _stops;
    int _route_size;
    Route(const Route&);
    Route&operator=(const Route&);
  virtual  void populateRoute(int number);

  virtual  void depopulateRoute();

public:
    Route(const QString& depart_station,int id,int route_size,QVector<QSharedPointer<Stops>>& stops);
    ~Route();
    const QSharedPointer<Train>& findByDate(int date);
    const QString& getDepartStation();
    const QVector<QString>& getArrivalStations();
    const int getId() const{return _route_id;}

    // JSON read/write
    void read(const QJsonObject &json);
    void write(QJsonObject &json);

const QString& getStationAt(int date);
//OBSOLETE
//const int getTimeAtStation(const QString& station);
void addArrivalStation(int date, QString station);



};

#endif // ROUTE_H
