#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QJsonObject>
class Ticket {
    static int ticketId;
public:

    Ticket(QString dname = "NA",QString aname ="NA",int pass=0,int train=0,int route=0,
           int wagon=0,int seat=0,int date=0,QString type="null",int discount=0,int type_id=0);

    // JSON read/write
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    QString print() const{
        QString res;
        res+=" Ticket: "+QString::number(_ticket_id);

        res+=" First Name: "+_first_name;

        res+=" Last Name: "+_last_name;

        res+=" Passenger id: "+QString::number(_passenger_id);

        res+= " train: "+QString::number(_train_id);

        res+=" wagon: "+QString::number(_wagon_number);

        res+=" seat: "+QString::number(_seat_number);

        res+=" date: "+QString::number(_date);


        res+=" type: "+_type;

        res+=" type_id:"+QString::number(_type_id);


        res+=" discount: "+QString::number(_discount);
        return res;
    }

    const int getTypeId(){return ownId();}
    const int getTicketId()const ;
    //IT SHOULD BE PURE VIRTUAL !!
    virtual ~Ticket(){};

    QString getDestName() const {return _first_name;}
    QString getArrivalName() const{return _last_name;}
    int getPassengerId() const{return _passenger_id;}
    int getTrainId() const {return _train_id;}
    int getRouteId() const{return _route_id;}
    int getWagonNumber() const{return _wagon_number;}
    int getSeatNumber() const {return _seat_number;}
    int getDate() const { return _date;}

private:
    const int ownId();
    int _ticket_id;
    QString _first_name;
    QString _last_name;
    int _passenger_id;
    int _train_id;
    int _route_id;
    int _wagon_number;
    int _seat_number;
    int _date;
    int _discount;
    QString _type;
    int _type_id;


    Ticket(Ticket&);
protected:



};


#endif // TICKET_H
