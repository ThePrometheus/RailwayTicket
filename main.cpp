#include <QCoreApplication>
#include "fullticket.h"
#include "studentticket.h"
#include <QDebug>
#include "ticketfordisabled.h"
#include "elderticket.h"
#include "seat.h"
#include"wagon.h"
#include "train.h"
#include "route.h"
#include "stops.h"
#include "station.h"
int main(int argc, char *argv[])
{Station s("frankfurt");

    QVector<QSharedPointer<Stops>> st(3);
    for(int i=0;i<3;++i){
Stops s(10,"Kiev");
QSharedPointer<Stops> sp(&s);
st.append(sp);



    }

    Route r (s.getStationName(),1,2,st);
    QSharedPointer<Route>  route1(&r);
    s.addRoute(route1);

  //  Train t1 (1,12,20);
//   qDebug()<< t1.getWagon(2)->getSeat(5)->getNumber();

  /*  Seat s (1);
    qDebug()<<s.getNumber()<<endl;
    Wagon w (2,5);
   qDebug()<< w.getSeat(3)->getNumber();
   qDebug()<<w.getSeat(10)->getNumber();
   qDebug()<<w.print()<<endl;

  /*  FullTicket ft("hello","Richardson",2,3,4,5,6,7);
    Ticket * t = &ft;
    qDebug()<<t->print();
    StudentTicket st("hello","Ivanov",2,3,4,5,6,7);
    qDebug()<<st.print()<<endl;
    TicketForDisabled tfd("HI","Hamlet",2,3,4,5,6,7);
    qDebug()<<tfd.print()<<endl;
qDebug()<<tfd.getTypeId();

qDebug()<<tfd.getTicketId();
ElderTicket  et("HI","Hamlet",2,3,4,5,6,7);
qDebug()<<et.print()<<endl;
qDebug()<<et.getTypeId()<<endl;
qDebug()<<et.getTicketId()<<endl;

ElderTicket et2("Frankfurt","Kiev",2,3,4,5,6,7);
qDebug()<<et2.print()<<endl;
qDebug()<<et2.getTypeId()<<endl;
qDebug()<<et2.getTicketId()<<endl;*/


    QCoreApplication a(argc, argv);

    return a.exec();
}

