#ifndef SEAT_H
#define SEAT_H
#include <QString>
class Seat{

private:
    int _seat_number;
    mutable bool _is_available;

public:
    Seat(int number=0);
    ~Seat();
    Seat(const Seat& s);
    Seat&operator=(const Seat& s);
    void makeAvailable() const;
    void makeUnavailable() const;
    bool isAvailable() const;
    const int getNumber() const;

};

bool operator ==(const Seat& s1, const Seat& s2);

#endif // SEAT_H
