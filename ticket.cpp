#include "ticket.h"
int Ticket::ticketId=0;

Ticket::Ticket(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount,int type_id):
    _ticket_id(ticketId++),_dest_name(dname),_arrival_station(aname),_passenger_id(pass),_train_id(train),_route_id(route),_wagon_number(wagon),_seat_number(seat),
    _date(date),_type(type),_discount(discount),_type_id(type_id){
#ifndef QT_NO_DEBUG
   qDebug()<<"Ticket created"<<endl;
#endif

};
const int Ticket::getTicketId()const{return  _ticket_id;}
const int Ticket::ownId(){return _type_id;}
