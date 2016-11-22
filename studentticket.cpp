#include"studentticket.h"
int StudentTicket::_studentId=0;

StudentTicket::StudentTicket(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount):
    Ticket( dname, aname, pass, train,route,wagon, seat, date,type,discount,_studentId++){
//_studentId++;
#ifndef QT_NO_DEBUG
qDebug()<< "Created student ticket";
#endif
};
//int StudentTicket::ownId(){return _studentId;}
