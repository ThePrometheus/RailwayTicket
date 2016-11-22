#include <QCoreApplication>
#include "fullticket.h"
#include "studentticket.h"
#include <QDebug>
#include "ticketfordisabled.h"
int main(int argc, char *argv[])
{
    FullTicket ft(1,"hello","Richardson",2,3,4,5,6,7);
    Ticket * t = &ft;
    qDebug()<<t->print();
    StudentTicket st(1,"hello","Ivanov",2,3,4,5,6,7);
    qDebug()<<st.print();
    TicketForDisabled tfd(1,"HI","HAmlet",2,3,4,5,6,7);
    qDebug()<<tfd.print();
qDebug()<<tfd.getTypeId();
    QCoreApplication a(argc, argv);

    return a.exec();
}

