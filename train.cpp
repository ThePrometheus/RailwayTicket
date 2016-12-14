#include <QString>
#include <QDebug>
#include <QVector>
#include <QSharedPointer>
#include "train.h"


Train::Train(int id,int date,int number_of_wagons):_train_id(id),_date(date),_train_size(number_of_wagons),
_wagons(new QVector<Wagon>){
    populateTrain(number_of_wagons);
#ifndef QT_NO_DEBUG
    qDebug()<<"New train created"<<endl;
#endif

}
Train::~Train(){
    depopulateTrain();
    delete _wagons;
#ifndef QT_NO_DEBUG
    qDebug()<<"train deleted"<<endl;
#endif
}

void Train::populateTrain(int number){
    for(int i=0;i<number;++i){
        _wagons->data()[i] = Wagon(i);
    }
}

void Train::depopulateTrain(){
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
