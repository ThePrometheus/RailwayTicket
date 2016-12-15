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
    QVector<Seat>* _seats;
public:
    void populateWagon();
    void depopulateWagon();
    Wagon(int number=0, int numberOfSeats=20);
    ~Wagon();
    Wagon(const Wagon&);
    Wagon&operator=(const Wagon&);
    const QString& print();

    const QSharedPointer<Seat>& getSeat(int i) const;
    const int getNumber() const {return _wagon_number;}
    const int getSize() const {return _wagon_size;}
    void changeNumber(int i);
    void bookSeat(int seat) const;
    const QVector<const Seat*> findSeats() const;

};

bool operator ==(const Wagon& w1, const Wagon& w2);

#endif // WAGON_H
