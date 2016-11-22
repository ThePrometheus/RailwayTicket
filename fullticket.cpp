#include "fullticket.h"
#include <iostream>
#include <string>
using namespace std;
int FullTicket::_fullId=0;

 FullTicket::FullTicket(QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount):
     Ticket(  dname, aname, pass, train,route,wagon, seat, date,type,discount,_fullId++){
     _fullId++;
#ifndef QT_NO_DEBUG
qDebug()<< "Created full ticket";
#endif
 };

