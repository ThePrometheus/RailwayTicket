#ifndef SEAT_H
#define SEAT_H
#include <QString>
class Seat{

private:
int _seat_number;
bool _is_available;
Seat(const Seat&);
Seat&operator=(const Seat&);

 public:
Seat(int number=0);
~Seat();
 void makeAvailable();
void makeUnavailable();
const int getNumber() const;



};

#endif // SEAT_H
