#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QClipboard>
#include <QComboBox>
#include <QFontComboBox>
#include <QLineEdit>
#include <QScrollArea>
#include <QCheckBox>
#include <QPushButton>
#include <QVector>
#include "seatwidget.h"
#include "ticketwidget.h"
#include "train.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // vector of strings while the data model isn't working properly
    MainWindow(int route, int date, const QVector<const Train*>& availableTrains);

public slots:
    void findWagons(const QString & wagon);
    void findSeats(const QString &seat);
    void chooseSeat(const QString &seat);
    void bookTicket();
    void fillSeat(const Ticket&);
private:
    void init();

    SeatWidget *seatWidget;
    TicketWidget *ticketWidget;
    QComboBox *trainCombo;
    QComboBox *wagonCombo;
    QScrollArea *scrollArea;
    QPushButton *bookButton;
    const QVector<const Train*> _availableTrains;
    QString _currSeat;
    int _route;
    int _date;
};

#endif // MAINWINDOW_H
