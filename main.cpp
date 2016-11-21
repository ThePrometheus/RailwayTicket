#include <QCoreApplication>
#include "fullticket.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    FullTicket ft(1,"hello","bybe",2,3,4,5,6,7);
    Ticket * t = &ft;
    qDebug()<<t->print();
    QCoreApplication a(argc, argv);

    return a.exec();
}

