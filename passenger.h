#ifndef PASSENGER_H
#define PASSENGER_H
class Passenger{
    static int passId;
private :
    QString _name;
    QString _info;
    //SHOULD BE REPLACED BY POINTER TO STRUCTURE OR ARRAY
    Ticket * ticket;


};

#endif // PASSENGER_H
