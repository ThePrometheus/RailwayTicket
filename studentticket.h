#ifndef STUDENTTICKET_H
#define STUDENTTICKET_H
#include "ticket.h"
#include <QString>
#include<QTextStream>
#include<iostream>
class StudentTicket:public Ticket{
public:
    StudentTicket(int id,QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type="student",int discount=50):
        Ticket( id, dname, aname, pass, train,route,wagon, seat, date,"student",50){
#ifndef QT_NO_DEBUG
  qDebug()<< "Created student ticket";
#endif
    };

    /* virtual ~FullTicket(){
 #ifndef QT_NO_DEBUG
   qDebug()<< "Deleted fullticket";
 #endif

 }*/

 private:
     StudentTicket operator=(const StudentTicket&);
     StudentTicket(const StudentTicket&);


};

#endif // STUDENTTICKET_H
