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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // vector of strings while the data model isn't working properly
    MainWindow(const QVector<QString>& availableTrains);

public slots:
    void findWagons(const QString &font);
    void findSeats(const QString &font);
    void chooseSeat(const QString &seat);
    void bookTicket();
    void fillSeat();
private:
    void init();

    SeatWidget *seatWidget;
    TicketWidget *ticketWidget;
    QComboBox *trainCombo;
    QComboBox *wagonCombo;
    QScrollArea *scrollArea;
    QPushButton *bookButton;
    const QVector<QString>& _availableTrains;
    QString _currSeat;
};

#endif // MAINWINDOW_H
