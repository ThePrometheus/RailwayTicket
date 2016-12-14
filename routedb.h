#ifndef ROUTEDB_H
#define ROUTEDB_H

#include <QVector>
#include <QSharedPointer>
#include <QString>
#include "route.h"
#include "ticket.h"

class RouteDb
{
public:
    // only for debug
    QVector<Route> _routes;
    RouteDb(const QString& filename = QString::null, const QString& filename2 = QString::null);
    ~RouteDb();

    void addRoute(const Route& r);
    void removeRoute(const Route& r);
    bool contains(const Route &r);

    void saveRoutes();

    const QVector<QSharedPointer<Route>> findRoutes(const QString &from, const QString &to);

private:
   // QVector<QSharedPointer<Route>> _routes;
    QString _rdb_location;
    QString _tdb_location;

    QVector<Ticket> _tickets;

    void loadRoutes();

    RouteDb(const RouteDb&);
    RouteDb operator=(const RouteDb&);
};

#endif // ROUTEDB_H
