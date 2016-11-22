#ifndef TICKETFORDISABLED_H
#define TICKETFORDISABLED_H
#include "ticket.h"
class TicketForDisabled:public Ticket{
    static int _disabledId;
public:
TicketForDisabled(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type="student",int discount=50);



    /* virtual ~FullTicket(){
 #ifndef QT_NO_DEBUG
   qDebug()<< "Deleted fullticket";
 #endif

 }*/
~TicketForDisabled();
 private:
int ownId();
    TicketForDisabled operator=(const TicketForDisabled&);
    TicketForDisabled(const TicketForDisabled&);


};
#endif // TICKETFORDISABLED_H
