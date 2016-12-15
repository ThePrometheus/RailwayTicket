#include "mainwindow.h"

#include <QLabel>
#include <QCheckBox>
#include <QScrollArea>
#include <QLineEdit>
#include <QApplication>
#include <QFontDatabase>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QPair>

MainWindow::MainWindow(int route, int date, const QVector<QPair<int,int>> availableTrainIds, const RouteDb &rdb) : _availableTrains(availableTrainIds),
    _currSeat(QString::null), _route(route), _date(date), _rdb(rdb)
{
    qDebug() << "LEN " << _availableTrains.size();
    QWidget *centralWidget = new QWidget;

    QLabel *trainLabel = new QLabel(tr("Train:"));
    trainCombo = new QComboBox;
    QLabel *wagonLabel = new QLabel(tr("Wagon:"));
    wagonCombo = new QComboBox;

    scrollArea = new QScrollArea;
    QVector<QString> seats;
        for (size_t i = 0; i < 20; ++i) {
            seats.push_back(QString::number(i+1));
        }
    seatWidget = new SeatWidget(seats);
    scrollArea->setWidget(seatWidget);

    bookButton = new QPushButton(tr("&Book seat"));

    connect(trainCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(findWagons(QString)));
    connect(wagonCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(findSeats(QString)));
    connect(wagonCombo, SIGNAL(currentIndexChanged(QString)),
             seatWidget, SLOT(updateSeats(QString)));
    connect(seatWidget, SIGNAL(seatSelected(QString)),
             this, SLOT(chooseSeat(QString)));

    connect(bookButton, SIGNAL(clicked()), this, SLOT(bookTicket()));

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(trainLabel);
    controlsLayout->addWidget(trainCombo, 1);
    controlsLayout->addWidget(wagonLabel);
    controlsLayout->addWidget(wagonCombo, 1);
    controlsLayout->addStretch(1);

    QHBoxLayout *lineLayout = new QHBoxLayout;
    lineLayout->addSpacing(12);
    lineLayout->addWidget(bookButton);

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addLayout(controlsLayout);
    centralLayout->addWidget(scrollArea, 1);
    centralLayout->addSpacing(4);
    centralLayout->addLayout(lineLayout);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("Buy the Ticket"));

    init();
}

void MainWindow::init()
{
    for (size_t i = 0; i < _availableTrains.size(); ++i) {
        int trainId = _availableTrains.at(i).second;
        trainCombo->addItem(QString::number(i+1)+ " " + QString::number(trainId));
    }
    if (_availableTrains.size() > 0)
        trainCombo->setCurrentIndex(0);
}

void MainWindow::chooseSeat(const QString &seat)
{
    _currSeat = seat;
}


void MainWindow::findWagons(const QString &wagon)
{
   /* QString currentItem = styleCombo->currentText();
    styleCombo->clear();

    QString style;
    foreach (style, fontDatabase.styles(font.family()))
        styleCombo->addItem(style);

    int styleIndex = styleCombo->findText(currentItem);

    if (styleIndex == -1)
        styleCombo->setCurrentIndex(0);
    else
        styleCombo->setCurrentIndex(styleIndex);*/

    const QPair<int,int> trainId = _availableTrains.at(trainCombo->currentIndex());
   /* QVector<QString> wagons(2);
    wagons.append(QString("1"));
    wagons.append(QString("2"));*/
    for (size_t i = 0; i < _rdb.findTrain(trainId.first, trainId.second).getSize(); ++i) {
        wagonCombo->addItem(QString::number(i+1));
    }
    if (_rdb.findTrain(trainId.first, trainId.second).getSize() > 0)
        wagonCombo->setCurrentIndex(0);
    qDebug("all set");
}

void MainWindow::findSeats(const QString &wagon)
{
    const QPair<int,int> ids = _availableTrains.at(trainCombo->currentIndex());
    /*if (_rdb.findTrain(ids.first, ids.second).getWagon(wagon.toInt()-1).getNumber() != -1) {
        qDebug() << "not -1";
        const QVector<const Seat*> seats = _rdb.findTrain(ids.first, ids.second).getWagon(wagon.toInt()-1).findSeats();
        qDebug() << seats.size();
    } else {
        qDebug() << "NA";
    }*/
   const QVector<QPair<int,int>>& b = _rdb.findTrain(ids.first, ids.second).getBookedSeats();
}

void MainWindow::bookTicket()
{
    if (_currSeat == QString::null) return;
    ticketWidget = new TicketWidget(trainCombo->currentText().toInt(),
                                    _route, wagonCombo->currentText().toInt(), _currSeat.toInt(), _date);
    connect(ticketWidget, SIGNAL(seatBooked(Ticket)), this, SLOT(fillSeat(Ticket)));
    ticketWidget->show();
}

void MainWindow::fillSeat(const Ticket &t)
{
    QMessageBox msgBox;
    if (_currSeat != QString::null)
        msgBox.setText(t.print());
    else msgBox.setText("N/A");
    msgBox.exec();
}

/*#ifndef QT_NO_CLIPBOARD
void MainWindow::updateClipboard()
{
    clipboard->setText(lineEdit->text(), QClipboard::Clipboard);
    clipboard->setText(lineEdit->text(), QClipboard::Selection);
}
#endif*/
