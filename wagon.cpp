#include "wagon.h"
#include<QDebug>
#include<QString>

Wagon::Wagon(int number,int size):_wagon_number(number),_wagon_size(size), _seats(new QVector<Seat>){
    //populateWagon(size);
#ifndef QT_NO_DEBUG
    // qDebug()<<"Wagon is created"<<endl;

#endif
}
Wagon::~Wagon(){
    depopulateWagon();
    delete _seats;
#ifndef QT_NO_DEBUG
    //qDebug()<<"Wagon is deleted"<<endl;
#endif
}


Wagon::Wagon(const Wagon& w) :_wagon_number(w.getNumber()), _wagon_size(w.getSize()), _seats(new QVector<Seat>)
{
    populateWagon(_wagon_size);
}

Wagon& Wagon::operator=(const Wagon& w) {
    if (this == &w)
        return *this;
    _wagon_number = w.getNumber();
    _wagon_size = w.getSize();
    _seats->clear();
    _seats = new QVector<Seat>;
    populateWagon(_wagon_size);
    return *this;
}


bool operator ==(const Wagon& w1, const Wagon& w2) {
    return (w1.getNumber() == w2.getNumber() && w1.getSize() == w2.getSize());
}


const QSharedPointer<Seat>& Wagon::getSeat(int i) const {
    if(i>=0&&i<_wagon_size) {
        QSharedPointer<Seat> ptr (&(_seats->operator [](i)));
        return ptr;
    }

}
const QString& Wagon::print(){
    _info="";
    for(int i=0;i<_seats->size();++i)
        _info+="Seat:"+_seats->at(i).getNumber();

    return _info;
}

void Wagon::changeNumber(int i){
    _wagon_number=i;
}
void Wagon::populateWagon(int number){
    for(int i=0;i<number;++i){
        Seat s(i);
        _seats->append(s);

    }
}

void Wagon::depopulateWagon(){
    qDebug() << "depopulate wagon";
    for(int i=0;i<_seats->size();++i){
        _seats->at(i).~Seat();
    }
    _seats->clear();

}

