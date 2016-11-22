#include "elderticket.h"

ElderTicket::ElderTicket(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount):
    Ticket( dname, aname, pass, train,route,wagon, seat, date,type,discount,_elderId++){

#ifndef QT_NO_DEBUG
qDebug()<< "Created elder ticket  ";
#endif
};

ElderTicket::~ElderTicket(){
#ifndef QT_NO_DEBUG
qDebug()<< "Deleted elder ticket";
#endif
}
int ElderTicket::_elderId=0;
