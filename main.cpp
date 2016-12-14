#include <QCoreApplication>
#include <QApplication>
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
#include "bahn.h"
#include "passenger.h"
#include "routedb.h"
// GUI
#include "findroutewindow.h"

int main(int argc, char *argv[])
{ /*QString pname= "Nazar";
    QString pinfo="Student";
    Passenger pass(pname,pinfo);
    Bahn bahn ;*/
    
    
   // Station s("frankfurt");
    /* bahn.addStation(&s);
    QSharedPointer<Station> ss = bahn.findDepartStation(s.getStationName());*/
    
   /* QVector<QSharedPointer<Stops>> st(3);
    for(int i=0;i<3;++i){
        Stops s(2000+i,"Kiev");
        qDebug()<<s.getDate()<<endl;
        QSharedPointer<Stops> sp(&s);
        qDebug()<<sp->getDate()<<endl;
        st.append(sp);

    }
   /* for(int i=0;i<2;++i){
        qDebug()<<"test:"<<st.at(i)->getDate()<<endl;
    }*/
   /* qDebug() << "end of test 1";
    
    Route r (s.getStationName(),1,2,st);
    QSharedPointer<Route> route1(&r);
    s.addRoute(route1);

    RouteDb rdb(QString("c:/tmpdata/routes.json"));
    rdb.addRoute(route1);
    qDebug() << rdb._routes.at(0);
    //  rdb.saveRoutes();
    
    /*Train t1 (1,12,20);
    //   qDebug()<< t1.getWagon(2)->getSeat(5)->getNumber();
    
    Seat seat (1);
    //  qDebug()<<seat.getNumber()<<endl;
    Wagon w (2,5);
    //  qDebug()<< w.getSeat(3)->getNumber();
    //  qDebug()<<w.getSeat(10)->getNumber();
    //qDebug()<<w.print()<<endl;
    
    FullTicket ft("hello","Richardson",2,3,4,5,6,7);
    Ticket * t = &ft;
    //  qDebug()<<t->print();
    StudentTicket stt("hello","Ivanov",2,3,4,5,6,7);
    //  qDebug()<<stt.print()<<endl;
    TicketForDisabled tfd("HI","Hamlet",2,3,4,5,6,7);
    //  qDebug()<<tfd.print()<<endl;
    //qDebug()<<tfd.getTypeId();
    
    //qDebug()<<tfd.getTicketId();
    ElderTicket  et("HI","Hamlet",2,3,4,5,6,7);
    /*qDebug()<<et.print()<<endl;
qDebug()<<et.getTypeId()<<endl;
qDebug()<<et.getTicketId()<<endl;
*/
    /* ElderTicket et2("Frankfurt","Kiev",2,3,4,5,6,7);*/
    /*qDebug()<<et2.print()<<endl;
qDebug()<<et2.getTypeId()<<endl;
qDebug()<<et2.getTicketId()<<endl;
*/
    
    // pass.addTicket(t);
    
    QApplication a(argc, argv);
    FindRouteWindow frwindow;
    frwindow.show();

    return a.exec();
}

