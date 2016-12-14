#ifndef TICKETWIDGET_H
#define TICKETWIDGET_H

#include <QWidget>
#include <QLineEdit>

class TicketWidget : public QWidget
{
    Q_OBJECT
public:
    TicketWidget(int pass,int train,int route,
                 int wagon,int seat,int date, QWidget *parent=0);

public slots:
    void echoChanged(int);
    void validatorChanged(int);
    void alignmentChanged(int);
    void inputMaskChanged(int);
    void accessChanged(int);

private:
    QLineEdit *echoLineEdit;
    QLineEdit *validatorLineEdit;
    QLineEdit *alignmentLineEdit;
    QLineEdit *inputMaskLineEdit;
    QLineEdit *accessLineEdit;

    int _pass;
    int _train;
    int _route;
    int _wagon;
    int _seat;
    int _date;
};

#endif // TICKETWIDGET_H
