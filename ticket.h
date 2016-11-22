#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QTextStream>
#include <QDebug>
class Ticket {

   public:
    Ticket(int id,QString dname,QString aname,int pass,int train,int route,int wagon,int seat,int date,QString type="null",int discount=0):
        _ticket_id(id),_dest_name(dname),_arrival_station(aname),_passenger_id(pass),_train_id(train),_route_id(route),_wagon_number(wagon),_seat_number(seat),
        _date(date),_type(type),_discount(discount){
#ifndef QT_NO_DEBUG
       qDebug()<<"Ticket created"<<endl;
#endif

    }
        ;
QString print(){
     QString res;
     res+=" Ticket: "+_ticket_id;
     res+=" Destination: "+_dest_name;
     res+=" Arrival: "+_arrival_station;
     res+=" Passenger id: "+_passenger_id;
     res+= " train: "+_train_id;
     res+=" wagon: "+_wagon_number;
     res+=" seat: "+_seat_number;
     res+=" date: "+_date;
     res+="type: "+_type;

     res+=" discount "+_discount;
return res;
 }
int getTypeId(){return ownId();}
//IT SHOULD BE PURE VIRTUAL !!
  virtual ~Ticket(){};
private:
virtual int ownId(){};
    int _ticket_id;
    QString _dest_name;
   QString _arrival_station;
    int _passenger_id;
    int _train_id;
    int _route_id;
    int _wagon_number;
    int _seat_number;
    int _date;
    int _discount;
    QString _type;


    Ticket(Ticket&);
protected:

 virtual int getTicketId() const {return _ticket_id;}
virtual QString getDestName() const {return _dest_name;}
 virtual QString getArrivalName() const{return _arrival_station;}
virtual int getPassengerId() const{return _passenger_id;}
  virtual int getTrainId() const {return _train_id;}
    virtual int getRouteId() const{return _route_id;}
    virtual int getWagonNumber() const{return _wagon_number;}
    virtual int getSeatNumber() const {return _seat_number;}
    virtual int getDate() const { return _date;}





};


#endif // TICKET_H
