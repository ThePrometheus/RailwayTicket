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

    const QVector<QPair<int, int> > findTrains(const QString &from, const QString &to, const int on) const;

    const Train& findTrain(int routeId, int trainId) const;
    const Route& findRoute(int index) const;

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
