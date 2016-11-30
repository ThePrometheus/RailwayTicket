#ifndef STOPS_H
#define STOPS_H
class Stops{
private:
    int _date;
    QString _station;

    Stops&operator=(const Stops&);
public:
    Stops(const Stops&);
    const int getDate()const {return _date;}
    const QString& getStation()const {return _station;}
Stops(int date,QString station);
~Stops();
};

#endif // STOPS_H
