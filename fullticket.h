#ifndef FULLTICKET_H
#define FULLTICKET_H
#include "ticket.h"
#include <QString>
#include<QTextStream>
#include<iostream>
class FullTicket:public Ticket{
public:
    FullTicket(int id,QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date):
        Ticket( id, dname, aname, pass, train,route,wagon, seat, date){
#ifndef QT_NO_DEBUG
  qDebug()<< "Createdfullticket";
#endif
    };

QString print();
   /* virtual ~FullTicket(){
#ifndef QT_NO_DEBUG
  qDebug()<< "Deleted fullticket";
#endif

}*/

private:
    FullTicket operator=(const FullTicket&);
    FullTicket(const FullTicket&);

};


#endif // FULLTICKET_H
