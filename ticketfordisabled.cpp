#include "ticketfordisabled.h"

TicketForDisabled::TicketForDisabled(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount):
    Ticket( dname, aname, pass, train,route,wagon, seat, date,type,discount,_disabledId++){

#ifndef QT_NO_DEBUG
    qDebug()<< "Created disabled ticket  ";
#endif
}

TicketForDisabled::~TicketForDisabled(){
#ifndef QT_NO_DEBUG
    qDebug()<< "Deleted disabled ticket  ticket";
#endif
}
int TicketForDisabled::_disabledId=0;

