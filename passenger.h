#ifndef PASSENGER_H
#define PASSENGER_H
#include <QVector>
#include "ticket.h"
#include <QSharedPointer>
#include <QString>

class Passenger{
private:
    Passenger(const Passenger&);
    Passenger& operator=(const Passenger&);
   QString _name;
   QString _info;
   QVector<QSharedPointer<Ticket>> _tickets;



public:
   Passenger (QString name, QString info);
   ~Passenger();
   void addTicket(Ticket * ticket);
   //TO-DO:DELETE TICKET



};


#endif // PASSENGER_H
