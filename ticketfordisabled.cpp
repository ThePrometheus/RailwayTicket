#include "ticketfordisabled.h"

TicketForDisabled::TicketForDisabled(int id,QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount):
    Ticket( id, dname, aname, pass, train,route,wagon, seat, date,"disabled",10){

#ifndef QT_NO_DEBUG
qDebug()<< "Created disabled ticket  ticket";
#endif
};

TicketForDisabled::~TicketForDisabled(){
#ifndef QT_NO_DEBUG
qDebug()<< "Deleted disabled ticket  ticket";
#endif
}
int TicketForDisabled::_disabledId=0;
int TicketForDisabled::ownId(){return _disabledId;}
