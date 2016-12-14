#include "routedb.h"
#include "stops.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QIODevice>

RouteDb::RouteDb(const QString &filename, const QString &filename2) : _rdb_location(filename), _tdb_location(filename2)
{
    //if (_db_location != QString::null)
        //loadRoutes();
}

RouteDb::~RouteDb() {
   // if (_db_location != QString::null)
        //saveRoutes();
    _routes.clear();
}

void RouteDb::addRoute(const QSharedPointer<Route> r) {
    if (!contains(r))
        _routes.append(r);
}

bool RouteDb::contains(const QSharedPointer<Route> r) {
    return _routes.contains(r);
}

void RouteDb::removeRoute(const QSharedPointer<Route> r) {
    _routes.removeOne(r);
}

const QVector<QSharedPointer<Route>> RouteDb::findRoutes(const QString &from, const QString &to) {
    QVector<QSharedPointer<Route>> res;
    foreach (const QSharedPointer<Route> r, _routes) {
        if (r->getDepartStation() == from && r->getArrivalStations().contains(to))
            res.append(r);
    }
    return res;
}

void RouteDb::loadRoutes() {
    QFile loafFile(_rdb_location);

    if (!loafFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file");
        return;
    }

    QJsonDocument loadDoc(QJsonDocument::fromJson(loafFile.readAll()));
    QJsonObject json = loadDoc.object();

    QJsonArray routes = json["routes"].toArray();
    _routes.clear();
    _routes.resize(routes.size());
    for (size_t i = 0; i < routes.size(); ++i) {
        QJsonObject obj = routes[i].toObject();
        QVector<QSharedPointer<Stops>> empty;
        Route r(QString::null, 0, 0, empty);
        r.read(obj);
        QSharedPointer<Route> rp(&r);
        qDebug() << "about to append " << rp->getDepartStation();
        qDebug() << _routes.at(0);
        _routes.push_back(rp);
    }

    qDebug() << "finished loading";
    loafFile.close();
}

void RouteDb::saveRoutes() {
    QFile saveFile(_rdb_location);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file");
        return;
    }

    QJsonObject json;
    QJsonArray arr;

    qDebug()<<"prior to cycle"<<endl;
    foreach (const QSharedPointer<Route> r, _routes) {
        QJsonObject obj;
        r.data()->write(obj);
        arr.append(obj);
    }
    qDebug()<<"after the cycle"<<endl;
    json["routes"] = arr;

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}
