#include <QString>
#include <QDebug>
#include <QVector>
#include <QSharedPointer>
#include "train.h"


Train::Train(int id,int date,int number_of_wagons):_train_id(id),_date(date),_train_size(number_of_wagons),
_wagons(new QVector<Wagon>){
    //populateTrain(number_of_wagons);
#ifndef QT_NO_DEBUG
    qDebug()<<"New train created"<<endl;
#endif

}
Train::~Train(){
    depopulateTrain();
    //delete _wagons;
#ifndef QT_NO_DEBUG
    qDebug()<<"train deleted"<<endl;
#endif
}

void Train::bookSeat(int wagon, int seat) const
{
    if (wagon > _wagons->size()) return;
    _wagons->at(wagon).bookSeat(seat);
}

void Train::populateTrain(){
    //qDebug() << number << " SIZE";
    for(int i=0;i<_train_size;++i){
        Wagon w(i);
        _wagons->append(w);
        _wagons->operator [](i).populateWagon();
    }

    qDebug() << "in populateTrain" << _wagons->size();
}

Train::Train(const Train &t) : _train_id(t.getId()), _date(t.getDate()), _train_size(t.getSize()), _wagons(new QVector<Wagon>)
{
    //populateTrain(_train_size);
}

Train& Train::operator =(const Train& t)
{
    if (this==&t)
        return *this;
    _train_id = t.getId();
    _train_size = t.getSize();
    _date = t.getDate();
    //depopulateTrain();
   //populateTrain(_train_size);
    return *this;
}

bool operator ==(const Train& t1, const Train& t2) {
    return (t1.getId() == t2.getId() && t1.getDate() == t2.getDate());
}

void Train::depopulateTrain(){
    //qDebug() << "depopulating train";
    for(int i=0;i<_wagons->size();++i){
        _wagons->at(i).~Wagon();
    }
    _wagons->clear();

}
const QSharedPointer<Wagon>& Train::getWagon(int i) const{
    if(i>=0&&i<_train_size) {
        QSharedPointer<Wagon> ptr(&(_wagons->operator [](i)));
        return ptr;
    }

}
