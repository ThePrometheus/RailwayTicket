#ifndef TRAIN_H
#define TRAIN_H
#include "wagon.h"
#include <QVector>
#include <QSharedPointer>
#include <QJsonObject>
class Train{

private:
    int _train_id;
    int _date;
    int _train_size;
    QVector<QSharedPointer<Wagon>>  _wagons;
    virtual void populateTrain(int number);
    virtual void depopulateTrain();
    Train(const Train&);
    Train&operator=(const Train&);
public:
    Train(int id,int date=20,int number_of_wagons=16);
    ~Train();
    inline const   int getId() const{return _train_id;}
    inline  const int getDate()const {return _date;}
    const QSharedPointer<Wagon>& getWagon(int i);
    void setDate(int date){_date=date;}

    // JSON read/write
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    //void setSize(int size);




};

#endif // TRAIN_H
