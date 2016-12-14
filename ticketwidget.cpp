#include "ticketwidget.h"
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>

TicketWidget::TicketWidget(int train,int route,
                           int wagon,int seat,int date, QWidget *parent) : QWidget(parent),
    _train(train),
    _seat(seat),
    _route(route),
    _wagon(wagon),
    _date(date),
    _type(0)
{
    QGroupBox *nameGroup = new QGroupBox(tr("Name"));

    QLabel *nameLabel = new QLabel(tr("First Name:"));
    QLabel *lastNameLabel = new QLabel(tr("Last Name:"));

    nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("Input first name");
    nameEdit->setFocus();
    lastNameEdit = new QLineEdit;
    lastNameEdit->setPlaceholderText("Input last name");

    QGroupBox *discountGroup = new QGroupBox(tr("Use a discount"));

    QLabel *discountLabel = new QLabel(tr("Type:"));
    QComboBox *idComboBox = new QComboBox;
    idComboBox->addItem(tr("None"));
    idComboBox->addItem(tr("Student ID#"));
    idComboBox->addItem(tr("Disabled ID#"));
    idComboBox->addItem(tr("Elder ID#"));
    discountIdLineEdit = new QLineEdit;
    discountIdLineEdit->setPlaceholderText("Input ID#");
    discountIdLineEdit->setReadOnly(true);

    priceLabel = new QLabel(tr("200 UAH"));
    QGroupBox *priceGroup = new QGroupBox(tr("Current price"));

    QGroupBox *bookGroup = new QGroupBox(tr(""));

    bookButton = new QPushButton(tr("Book"));
    connect(bookButton, SIGNAL(clicked()), this, SLOT(bookPressed()));

    connect(idComboBox, SIGNAL(activated(int)),
            this, SLOT(discountChanged(int)));

    QGridLayout *nameLayout = new QGridLayout;
    nameLayout->addWidget(nameLabel, 0, 0);
    nameLayout->addWidget(nameEdit, 1, 0, 1, 2);
    nameLayout->addWidget(lastNameLabel, 2, 0);
    nameLayout->addWidget(lastNameEdit, 3, 0, 1, 3);
    nameGroup->setLayout(nameLayout);

    QGridLayout *discountLayout = new QGridLayout;
    discountLayout->addWidget(discountLabel, 0, 0);
    discountLayout->addWidget(idComboBox, 0, 1);
    discountLayout->addWidget(discountIdLineEdit, 1, 0, 1, 2);
    discountGroup->setLayout(discountLayout);

    QGridLayout *priceLabelLayout = new QGridLayout;
    priceLabelLayout->addWidget(priceLabel, 0, 0);
    priceGroup->setLayout(priceLabelLayout);

    QGridLayout *bookLayout = new QGridLayout;
    bookLayout->addWidget(bookButton, 0, 0);
    bookGroup->setLayout(bookLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nameGroup, 0, 0);
    layout->addWidget(discountGroup, 1, 0);
    layout->addWidget(priceGroup, 2, 0);
    // layout->addWidget(priceGroup, 0, 1);
    layout->addWidget(bookGroup, 3, 0);
    setLayout(layout);

    setWindowTitle(tr("Ticket"));
}


void TicketWidget::discountChanged(int index)
{
    switch (index) {
    case 0:
        discountIdLineEdit->setReadOnly(true);
        _type = 0;
        break;
    case 1:
        discountIdLineEdit->setReadOnly(false);
        _type = 1;
        break;
    case 2:
        discountIdLineEdit->setReadOnly(false);
        _type = 2;
        break;
    case 3:
        discountIdLineEdit->setReadOnly(false);
        _type = 3;
        break;
    }
    discountIdLineEdit->clear();
}

void TicketWidget::bookPressed()
{
    const QString fname(nameEdit->text());
    const QString lname(lastNameEdit->text());
    int id = -1;

    if (fname.isEmpty() || lname.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Input your full name");
        msgBox.exec();
        return;
    }
    if (_type != 0 && discountIdLineEdit->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Input your ID number");
        msgBox.exec();
        return;
    } else {
        id = discountIdLineEdit->text().toInt();
    }

    switch (_type) {
    case 0:
        _ticket = new FullTicket(fname, lname, id, _train, _route, _wagon, _seat, _date);
        break;
    case 1:
        _ticket = new StudentTicket(fname, lname, id, _train, _route, _wagon, _seat, _date);
        break;
    case 2:
        _ticket = new TicketForDisabled(fname, lname, id, _train, _route, _wagon, _seat, _date);
        break;
    case 3:
        _ticket = new ElderTicket(fname, lname, id, _train, _route, _wagon, _seat, _date);
        break;
    }

    emit seatBooked();
    this->close();
}
