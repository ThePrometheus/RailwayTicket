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
    QFile loadFileR(_rdb_location);
    QFile loadFileT(_tdb_location);

    if (!loadFileR.open(QIODevice::ReadOnly) || !loadFileT.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save files");
        return;
    }

    QJsonDocument loadDocR(QJsonDocument::fromJson(loadFileR.readAll()));
    QJsonObject jsonR = loadDocR.object();
    QJsonDocument loadDocT(QJsonDocument::fromJson(loadFileT.readAll()));
    QJsonObject jsonT = loadDocT.object();

    QJsonArray routes = jsonR["routes"].toArray();
    _routes->clear();
    size_t lim = routes.size();
    for (size_t i = 0; i < lim; ++i) {
        Route r;
        (*_routes).append(r);
    }
    for (size_t i = 0; i < lim; ++i) {
        QJsonObject obj = routes[i].toObject();
        (*_routes).operator [](i).read(obj);
        (*_routes).operator [](i).populateRoute();
    }
    foreach (const Route& r, (*_routes)) {
        qDebug() << r.getDepartStation() << " " << r.getArrivalStations().size();

        foreach (const QString& str, r.getArrivalStations()) {
            qDebug() << str;
        }
    }
    loadFileR.close();

    QJsonArray tickets = jsonT["tickets"].toArray();

    loadFileT.close();
}

void RouteDb::saveRoutes() {
    QFile saveFileR(_rdb_location);

    if (!saveFileR.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save files");
        return;
    }

    QJsonObject jsonr;
    QJsonArray arr;

    for (size_t i = 0; i < _routes->size(); ++i) {
        QJsonObject obj;
        _routes->at(i).write(obj);
        arr.append(obj);
    }
    jsonr["routes"] = arr;

    QJsonDocument saveDocR(jsonr);
    saveFileR.write(saveDocR.toJson());
    saveFileR.close();
    saveTickets();
}

void RouteDb::saveTickets()
{
    QFile saveFileT(_tdb_location);

    if (!saveFileT.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file");
        return;
    }

    QJsonObject jsont;
    QJsonArray arrt;

    for (size_t i = 0; i < _tickets->size(); ++i) {
        QJsonObject obj;
        _tickets->at(i).write(obj);
        arrt.append(obj);
    }
    jsont["tickets"] = arrt;

    QJsonDocument saveDocT(jsont);
    saveFileT.write(saveDocT.toJson());
    saveFileT.close();
}
