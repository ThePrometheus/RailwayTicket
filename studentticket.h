#ifndef STUDENTTICKET_H
#define STUDENTTICKET_H
#include "ticket.h"
#include <QString>
#include<QTextStream>
#include<iostream>
class StudentTicket:public Ticket{
static int _studentId;
public:
StudentTicket(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type="student",int discount=50);



    /* virtual ~FullTicket(){
 #ifndef QT_NO_DEBUG
   qDebug()<< "Deleted fullticket";
 #endif

 }*/

 private:
int ownId();
     StudentTicket operator=(const StudentTicket&);
     StudentTicket(const StudentTicket&);


};

#endif // STUDENTTICKET_H
