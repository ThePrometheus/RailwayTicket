#ifndef TICKETWIDGET_H
#define TICKETWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "ticket.h"
#include "ticketfordisabled.h"
#include "studentticket.h"
#include "fullticket.h"
#include "elderticket.h"

class TicketWidget : public QWidget
{
    Q_OBJECT
public:
    TicketWidget(int train, int route,
                 int wagon, int seat, int date, QWidget *parent=0);

public slots:
    void discountChanged(int);
    void bookPressed();

signals:
    void seatBooked();

private:
    QLineEdit *nameEdit;
    QLineEdit *lastNameEdit;
    QLabel *priceLabel;
    QLineEdit *discountIdLineEdit;
    QPushButton *bookButton;

    int _train;
    int _route;
    int _wagon;
    int _seat;
    int _date;

    int _type;
    Ticket *_ticket;
};

#endif // TICKETWIDGET_H
