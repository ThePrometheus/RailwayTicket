#ifndef WAGON_H
#define WAGON_H
#include<QDebug>
#include<QVector>
#include<QSharedPointer>
#include"seat.h"
#include<QString>
class Wagon{
private:
    int _wagon_number;
    int _wagon_size;
    QString _info;
    QVector<QSharedPointer<Seat>> _seats;
    Wagon(const Wagon&);
    Wagon&operator=(const Wagon&);
    void populateWagon(int number);
    void depopulateWagon();

public:
    Wagon(int number=0, int numberOfSeats=20);
    ~Wagon();
    const QString& print();

  const   QSharedPointer<Seat>& getSeat(int i);
    void changeNumber(int i);




};

#endif // WAGON_H
