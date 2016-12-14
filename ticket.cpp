#include "ticket.h"
int Ticket::ticketId=0;

Ticket::Ticket(QString dname, QString aname, int pass, int train, int route, int wagon, int seat, int date, QString type, int discount, int type_id):
    _ticket_id(ticketId++),_first_name(dname),_last_name(aname),_passenger_id(pass),_train_id(train),_route_id(route),_wagon_number(wagon),_seat_number(seat),
    _date(date),_type(type),_discount(discount),_type_id(type_id){
#ifndef QT_NO_DEBUG
    qDebug()<<"Ticket created"<<endl;
#endif

}

Ticket::Ticket(const Ticket& t) : _ticket_id(ticketId++), _first_name(t.getFirstName()),
    _last_name(t.getLastName()), _passenger_id(t.getPassengerId()), _train_id(t.getTrainId()),
    _route_id(t.getRouteId()), _date(t.getDate()), _wagon_number(t.getWagonNumber()), _seat_number(t.getSeatNumber()),
    _discount(t.getDiscount()), _type_id(t.getTypeId())
{

}

Ticket& Ticket::operator=(const Ticket& t) {
    if (this==&t)
        return *this;
    _first_name = t.getFirstName();
    _last_name = t.getLastName();
    _passenger_id = t.getPassengerId();
    _train_id = t.getTrainId();
    _route_id = t.getRouteId();
    _date = t.getDate();
    _wagon_number = t.getWagonNumber();
    _seat_number = t.getSeatNumber();
    _discount = t.getDiscount();
    _type_id = t.getTypeId();
    return *this;
}

bool operator ==(const Ticket& t1, const Ticket& t2) {
    return (t1.getTrainId() == t2.getTrainId() && t1.getWagonNumber() == t2.getWagonNumber()
            && t1.getSeatNumber() == t2.getSeatNumber() && t1.getDate() == t2.getDate());
}

const int Ticket::getTicketId()const{return  _ticket_id;}
const int Ticket::ownId() const{return _type_id;}

void Ticket::read(const QJsonObject &json) {
    _first_name = json["firstName"].toString();
    _last_name = json["lastName"].toString();
    _passenger_id = json["passengerId"].toInt();
    _train_id = json["trainId"].toInt();
    _route_id = json["routeId"].toInt();
    _wagon_number = json["wagonNumber"].toInt();
    _seat_number = json["seatNumber"].toInt();
    _date = json["date"].toInt();
    _discount = json["discount"].toInt();
    _type_id = json["typeId"].toInt();
}

void Ticket::write(QJsonObject &json) const {
    json["firstName"] = _first_name;
    json["lastName"] = _last_name;
    json["passengerId"] = _passenger_id;
    json["trainId"] = _train_id;
    json["routeId"] = _route_id;
    json["wagonNumber"] = _wagon_number;
    json["seatNumber"] = _seat_number;
    json["date"] = _date;
    json["discount"] = _discount;
    json["typeId"] = _type_id;
}
