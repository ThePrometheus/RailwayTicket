#include "fullticket.h"
#include <iostream>
#include <string>
using namespace std;
int FullTicket::_fullId=0;
 int FullTicket::ownId(){return _fullId;}
 FullTicket::FullTicket(int id,QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type,int discount):
     Ticket( id, dname, aname, pass, train,route,wagon, seat, date,type,discount){
     _fullId++;
#ifndef QT_NO_DEBUG
qDebug()<< "Createdfullticket";
#endif
 };

