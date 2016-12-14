#include "ticketwidget.h"
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>

TicketWidget::TicketWidget(int pass,int train,int route,
                           int wagon,int seat,int date, QWidget *parent) : QWidget(parent),
                                                                           _pass(pass),
                                                                           _train(train),
                                                                           _seat(seat),
                                                                           _route(route),
                                                                           _wagon(wagon),
                                                                           _date(date),
                                                                           _type(new QString("adult"))
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

void TicketWidget::echoChanged(int index)
{
   /* switch (index) {
    case 0:
        nameEdit->setEchoMode(QLineEdit::Normal);
        break;
    case 1:
        nameEdit->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        nameEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        break;
    case 3:
        nameEdit->setEchoMode(QLineEdit::NoEcho);
    }*/
}

void TicketWidget::discountChanged(int index)
{
    switch (index) {
    case 0:
        discountIdLineEdit->clear();
        discountIdLineEdit->setReadOnly(true);
        _type = new QString("adult");
        break;
    case 1:
        discountIdLineEdit->clear();
        discountIdLineEdit->setReadOnly(false);
        _type = new QString("student");
        break;
    case 2:
        discountIdLineEdit->clear();
        discountIdLineEdit->setReadOnly(false);
        _type = new QString("disabled");
        break;
    case 3:
        discountIdLineEdit->clear();
        discountIdLineEdit->setReadOnly(false);
        _type = new QString("elder");
        break;
    }

    //lastNameEdit->clear();
}

void TicketWidget::alignmentChanged(int index)
{
   /* switch (index) {
    case 0:
        alignmentLineEdit->setAlignment(Qt::AlignLeft);
        break;
    case 1:
        alignmentLineEdit->setAlignment(Qt::AlignCenter);
        break;
    case 2:
        alignmentLineEdit->setAlignment(Qt::AlignRight);
    }*/
}

void TicketWidget::inputMaskChanged(int index)
{
   /* switch (index) {
    case 0:
        discountIdLineEdit->setInputMask("");
        break;
    case 1:
        discountIdLineEdit->setInputMask("+99 99 99 99 99;_");
        break;
    case 2:
        discountIdLineEdit->setInputMask("0000-00-00");
        discountIdLineEdit->setText("00000000");
        discountIdLineEdit->setCursorPosition(0);
        break;
    case 3:
        discountIdLineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
    }*/
}

void TicketWidget::accessChanged(int index)
{
    /*switch (index) {
    case 0:
        accessLineEdit->setReadOnly(false);
        break;
    case 1:
        accessLineEdit->setReadOnly(true);
    }*/
}

