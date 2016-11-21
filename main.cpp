#include <QCoreApplication>
#include "fullticket.h"
#include "studentticket.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    FullTicket ft(1,"hello","Richardson",2,3,4,5,6,7);
    Ticket * t = &ft;
    qDebug()<<t->print();
    StudentTicket st(1,"hello","Ivanov",2,3,4,5,6,7,"haha",12);
    qDebug()<<st.print();
    QCoreApplication a(argc, argv);

    return a.exec();
}

