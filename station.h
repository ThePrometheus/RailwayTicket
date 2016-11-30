#ifndef STATION_H
#define STATION_H
#include <QString>
#include<QSharedPointer>
#include "route.h"
class Station{
private:
    QString _station_name;
    QVector<QSharedPointer<Route>> _depart_routes;
    Station(const Station&);
    Station& operator=(const Station&);
public:
    Station(QString name);
    ~Station();
    void addRoute(const QSharedPointer<Route>&);
   QString getStationName();
   const QSharedPointer<Route>& getRoute(int id);



};

#endif // STATION_H
