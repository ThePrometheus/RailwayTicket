#ifndef ELDERTICKET_H
#define ELDERTICKET_H
#include "ticket.h"
class ElderTicket:public Ticket{
    static int _elderId;
public:
ElderTicket(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type="elder",int discount=10);



    /* virtual ~FullTicket(){
 #ifndef QT_NO_DEBUG
   qDebug()<< "Deleted fullticket";
 #endif

 }*/
~ElderTicket();
 private:
int ownId();
    ElderTicket operator=(const ElderTicket&);
    ElderTicket(const ElderTicket&);


};
#endif // ELDERTICKET_H
