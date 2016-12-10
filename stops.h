#ifndef STOPS_H
#define STOPS_H

#include <QJsonObject>
class Stops{
private:
    int _date;
    QString _station;

    Stops&operator=(const Stops&);
public:
    Stops(const Stops&);
    const int getDate()const {return _date;}
    const QString& getStation()const {return _station;}
    Stops(int date = 0, QString station = QString::null);
    ~Stops();

    // JSON read/write
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
};

#endif // STOPS_H
