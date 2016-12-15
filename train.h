#ifndef TRAIN_H
#define TRAIN_H
#include "wagon.h"
#include <QVector>
#include <QSharedPointer>
#include <QJsonObject>
#include <QPair>
class Train{

private:
    int _train_id;
    int _date;
    int _train_size;
    QVector<Wagon>* _wagons;
    mutable QVector<QPair<int,int>> _bookedSeats;
public:
    virtual void populateTrain();
    virtual void depopulateTrain();
    Train(int id=0,int date=2016,int number_of_wagons=16);
    ~Train();
    Train(const Train&);
    Train&operator=(const Train&);
    inline const   int getId() const{return _train_id;}
    inline  const int getDate()const {return _date;}
    inline  const int getSize()const {return _train_size;}
    inline  const QVector<QPair<int,int>>& getBookedSeats()const {return _bookedSeats;}
    const Wagon& getWagon(int i) const;
    void setDate(int date){_date=date;}

    void bookSeat(int wagon, int seat) const;
};

bool operator ==(const Train& t1, const Train& t2);

#endif // TRAIN_H
