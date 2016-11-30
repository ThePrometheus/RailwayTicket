#include "wagon.h"
#include<QDebug>
#include<QString>

Wagon::Wagon(int number,int size):_wagon_number(number),_wagon_size(size){
    populateWagon(size);
#ifndef QT_NO_DEBUG
    qDebug()<<"Wagon is created"<<endl;

#endif
}
Wagon::~Wagon(){
    depopulateWagon();
#ifndef QT_NO_DEBUG
    qDebug()<<"Wagon is deleted"<<endl;
#endif
}
 const QSharedPointer<Seat>& Wagon::getSeat(int i){
  if(i>=0&&i<_wagon_size)return _seats.at(i);

}
const QString& Wagon::print(){
    _info="";
for(int i=0;i<_seats.size();++i)
_info+="Seat:"+_seats.at(i)->getNumber();

return _info;
}

void Wagon::changeNumber(int i){
    _wagon_number=i;
}
void Wagon::populateWagon(int number){
_seats= QVector<QSharedPointer<Seat>>(number);
for(int i=0;i<number;++i){
 _seats[i] = QSharedPointer<Seat>(new Seat(i));
}
}

void Wagon::depopulateWagon(){
    for(int i=0;i<_seats.size();++i){
        _seats.at(i)->~Seat();
    }
    _seats.clear();

}

