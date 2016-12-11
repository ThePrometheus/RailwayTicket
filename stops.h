#ifndef STOPS_H
#define STOPS_H

#include <QJsonObject>
class Stops{
private:
    int _date;
    QString _station;

public:
    Stops(int date = 0, QString station = QString("NA"));
    ~Stops();
    Stops(const Stops&);
    Stops&operator=(const Stops&);
    const int getDate()const {return _date;}
    const QString& getStation()const {return _station;}

    // JSON read/write
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

#endif // STOPS_H
