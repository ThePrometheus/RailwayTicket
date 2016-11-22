#ifndef FULLTICKET_H
#define FULLTICKET_H
#include "ticket.h"
#include <QString>
#include<QTextStream>
#include<iostream>
class FullTicket:public Ticket{
    static int _fullId;
public:
    FullTicket(int id,QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type="adult",int discount=0);




   /* virtual ~FullTicket(){
#ifndef QT_NO_DEBUG
  qDebug()<< "Deleted fullticket";
#endif

}*/

private:
int ownId();
    FullTicket operator=(const FullTicket&);
    FullTicket(const FullTicket&);

};


#endif // FULLTICKET_H
