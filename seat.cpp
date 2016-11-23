#include "seat.h"
#include <QDebug>
Seat::Seat(int number):_seat_number(number),_is_available(true){
#ifndef QT_NO_DEBUG
    qDebug()<<"Seat is created"<<endl;
#endif

}
 void Seat::makeAvailable(){
 _is_available==false?_is_available=true : 0;
}
 void Seat::makeUnavailable(){
   _is_available==true?_is_available=false: 0;
 }
 const int Seat::getNumber()const {
     return this->_seat_number;
 }
 bool Seat::isAvailable(){
     return _is_available;
 }

Seat::~Seat(){
#ifndef QT_NO_DEBUG
    qDebug()<<"Seat is created"<<endl;
#endif
}
