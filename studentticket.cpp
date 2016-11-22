#include"studentticket.h"
int StudentTicket::_studentId=0;

StudentTicket::StudentTicket(int id,QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount):
    Ticket( id, dname, aname, pass, train,route,wagon, seat, date,type,discount){
_studentId++;
#ifndef QT_NO_DEBUG
qDebug()<< "Created student ticket";
#endif
};
int StudentTicket::ownId(){return _studentId;}
