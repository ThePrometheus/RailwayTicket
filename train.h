#ifndef TRAIN_H
#define TRAIN_H
#include "wagon.h"
#include <QVector>
#include <QSharedPointer>
class Train{

private:
    int _train_id;
    int _date;
    int _train_size;
    QVector<QSharedPointer<Wagon>>  _wagons;
    virtual void populateTrain(int number);
    virtual void depopulateTrain();
public:
    Train(int id,int date,int number_of_wagons=16);
    ~Train();
  inline   int getId(){return _train_id;}
  inline   int getDate(){return _date;}
const QSharedPointer<Wagon>& getWagon(int i);



};

#endif // TRAIN_H
