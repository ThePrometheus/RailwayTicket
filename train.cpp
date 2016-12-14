#include <QString>
#include <QDebug>
#include <QVector>
#include <QSharedPointer>
#include "train.h"


Train::Train(int id,int date,int number_of_wagons):_train_id(id),_date(date),_train_size(number_of_wagons){
    populateTrain(number_of_wagons);
#ifndef QT_NO_DEBUG
    qDebug()<<"New train created"<<endl;
#endif

}
Train::~Train(){
    depopulateTrain();
#ifndef QT_NO_DEBUG
    qDebug()<<"train deleted"<<endl;
#endif
}

void Train::populateTrain(int number){
    _wagons=QVector<QSharedPointer<Wagon>>(number);
    for(int i=0;i<number;++i){
        _wagons[i] = QSharedPointer<Wagon>(new Wagon(i));
    }
}

void Train::depopulateTrain(){
    for(int i=0;i<_wagons.size();++i){
        _wagons.at(i)->~Wagon();
    }
    _wagons.clear();

}
const QSharedPointer<Wagon>& Train::getWagon(int i){
    if(i>=0&&i<_train_size)return _wagons.at(i);

}
