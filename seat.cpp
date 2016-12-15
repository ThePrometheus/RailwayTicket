#include "seat.h"
#include <QDebug>
Seat::Seat(int number):_seat_number(number),_is_available(true){
#ifndef QT_NO_DEBUG
    //qDebug()<<"Seat is created"<<endl;
#endif

}

Seat::Seat(const Seat &s) : _seat_number(s.getNumber()), _is_available(s.isAvailable()){}

Seat& Seat::operator =(const Seat& s)
{
    if(this == &s)
        return *this;
    _seat_number = s.getNumber();
    _is_available = s.isAvailable();
    return *this;
}


bool operator ==(const Seat& s1, const Seat& s2){
    return (s1.getNumber() == s2.getNumber());
}

void Seat::makeAvailable() const{
    _is_available==false?_is_available=true : 0;
}
void Seat::makeUnavailable() const{
    _is_available==true?_is_available=false: 0;
}
const int Seat::getNumber()const {
    return this->_seat_number;
}
bool Seat::isAvailable() const{
    return _is_available;
}

Seat::~Seat(){
#ifndef QT_NO_DEBUG
    // qDebug()<<"Seat is deleted"<<endl;
#endif
}
