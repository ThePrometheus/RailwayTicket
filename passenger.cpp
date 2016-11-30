#include <QVector>
#include <QSharedPointer>
#include "passenger.h"
#include "ticket.h"

Passenger::Passenger(QString name, QString info):_name(name),_info(info){
qDebug()<<"Passenger is created"<<endl;

}
Passenger::~Passenger(){
    qDebug()<<"Passenger is deleted"<<endl;
}
void Passenger::addTicket(Ticket * ticket){
_tickets.append(QSharedPointer<Ticket>(ticket));
qDebug()<<"Ticket added"<<endl;
}
//TO-DO :DELETE TICKET

