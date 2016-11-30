#ifndef BAHN_H
#define BAHN_H
#include <QVector>
#include <QSharedPointer>
#include "station.h"
class Bahn{
private:
    QVector<QSharedPointer<Station>>  _stations;
    Bahn(const Bahn&);
    Bahn& operator=(const Bahn&);
public:
    Bahn();
    ~Bahn();
    const QSharedPointer<Station>& findDepartStation(QString query);
 void addStation( Station *);
};

#endif // BAHN_H
