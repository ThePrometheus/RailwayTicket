#ifndef ROUTEDB_H
#define ROUTEDB_H

#include <QVector>
#include <QSharedPointer>
#include <QString>
#include "route.h"

class RouteDb
{
public:
    RouteDb(const QString& filename = QString::null);
    ~RouteDb();

    void setLocation(const QString& filename);
    void addRoute(const QSharedPointer<Route> r);
    void removeRoute(const QSharedPointer<Route> r);
    bool contains(const QSharedPointer<Route> r);

    void saveRoutes();

    const QVector<QSharedPointer<Route>> findRoutes(const QString &from, const QString &to);

private:
    QVector<QSharedPointer<Route>> _routes;
    QString _db_location;

    void loadRoutes();

    RouteDb(const RouteDb&);
    RouteDb operator=(const RouteDb&);
};

#endif // ROUTEDB_H
