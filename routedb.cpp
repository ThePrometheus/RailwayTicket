#include "routedb.h"
#include "stops.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QIODevice>

RouteDb::RouteDb(const QString &filename, const QString &filename2) : _rdb_location(filename),
    _tdb_location(filename2), _routes(new QVector<Route>), _tickets(new QVector<Ticket>)
{
    //if (_db_location != QString::null)
        //loadRoutes();
}

RouteDb::~RouteDb() {
   // if (_db_location != QString::null)
        //saveRoutes();
    _routes->clear();
    _tickets->clear();
    //delete _tickets;
    //delete _routes;
}

void RouteDb::addRoute(const Route &r) {
    if (!contains(r))
        _routes->append(r);
}

bool RouteDb::contains(const Route &r) {
    return _routes->contains(r);
}

void RouteDb::removeRoute(const Route &r) {
    _routes->removeOne(r);
}

const QVector<QSharedPointer<Route>> RouteDb::findRoutes(const QString &from, const QString &to) {
    QVector<QSharedPointer<Route>> res;
    for (size_t i = 0; i < _routes->size(); ++i) {
        if (_routes->at(i).getDepartStation() == from && _routes->at(i).getArrivalStations().contains(to)) {
            QSharedPointer<Route> ptr(&(_routes->data()[i]));
            res.append(ptr);
        }
    }
    return res;
}

void RouteDb::loadRoutes() {
    QFile loadFile(_rdb_location);
    //QFile loadFile(_tdb_location);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file");
        return;
    }

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadFile.readAll()));
    QJsonObject json = loadDoc.object();

    QJsonArray routes = json["routes"].toArray();
    _routes->clear();
    size_t lim = routes.size();
    for (size_t i = 0; i < lim; ++i) {
        QJsonObject obj = routes[i].toObject();
        Route r;
        (*_routes).append(r);
        (*_routes).operator [](i).read(obj);
        (*_routes).operator [](i).populateRoute();
    }
    qDebug() << "out of loop";
    foreach (const Route& r, (*_routes)) {
        qDebug() << r.getDepartStation() << " " << r.getArrivalStations().size();
        foreach (const QString& str, r.getArrivalStations()) {
            qDebug() << str;
        }
    }
    qDebug() << "finished loading";
    loadFile.close();
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
    for (size_t i = 0; i < _routes->size(); ++i) {
        QJsonObject obj;
        _routes->at(i).write(obj);
        arr.append(obj);
    }
    qDebug()<<"after the cycle"<<endl;
    json["routes"] = arr;

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
}
