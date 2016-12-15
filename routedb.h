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
    RouteDb(const QString& filename = QString::null, const QString& filename2 = QString::null);
    ~RouteDb();

    void addRoute(const Route& r);
    void removeRoute(const Route& r);
    bool contains(const Route &r);

    void loadRoutes();
    void saveRoutes();
    void saveTickets();

    const QVector<QSharedPointer<Route>> findRoutes(const QString &from, const QString &to);

private:
    QString _rdb_location;
    QString _tdb_location;

    QVector<Route> *_routes;
    QVector<Ticket> *_tickets;

    void rememberSeat(const Ticket& t);

    RouteDb(const RouteDb&);
    RouteDb operator=(const RouteDb&);
};

#endif // ROUTEDB_H
