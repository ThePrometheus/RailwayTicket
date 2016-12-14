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

MainWindow::MainWindow(int route, int date, const QVector<QString>& availableTrains) : _availableTrains(availableTrains),
    _currSeat(QString::null), _route(route), _date(date)
{
    QWidget *centralWidget = new QWidget;

    QLabel *trainLabel = new QLabel(tr("Train:"));
    trainCombo = new QComboBox;
    QLabel *wagonLabel = new QLabel(tr("Wagon:"));
    wagonCombo = new QComboBox;

    scrollArea = new QScrollArea;
    QVector<QString> seats(0);
        for (char i = '0'; i <= '9'; ++i) {
            QString str(i);
            seats.push_back(str);
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
    foreach (const QString& train, _availableTrains) {
        if (!train.isEmpty() && !train.isNull())
            trainCombo->addItem(train);
    }
    if (_availableTrains.size() > 0)
        trainCombo->setCurrentIndex(0);
}

void MainWindow::chooseSeat(const QString &seat)
{
    _currSeat = seat;
}


void MainWindow::findWagons(const QString &font)
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

    QVector<QString> wagons(2);
    wagons.append(QString("1"));
    wagons.append(QString("2"));
    foreach (const QString& w, wagons) {
        if (!w.isEmpty() && !w.isNull())
            wagonCombo->addItem(w);
    }
    if (wagons.size() > 0)
        wagonCombo->setCurrentIndex(0);
}

void MainWindow::findSeats(const QString &font)
{
    /*QString currentSize = sizeCombo->currentText();
    sizeCombo->blockSignals(true);
    sizeCombo->clear();

    int size;
    if(fontDatabase.isSmoothlyScalable(font.family(), fontDatabase.styleString(font))) {
        foreach(size, QFontDatabase::standardSizes()) {
            sizeCombo->addItem(QVariant(size).toString());
            sizeCombo->setEditable(true);
        }

    } else {
        foreach(size, fontDatabase.smoothSizes(font.family(), fontDatabase.styleString(font))) {
            sizeCombo->addItem(QVariant(size).toString());
            sizeCombo->setEditable(false);
        }
    }

    sizeCombo->blockSignals(false);

    int sizeIndex = sizeCombo->findText(currentSize);

    if(sizeIndex == -1)
        sizeCombo->setCurrentIndex(qMax(0, sizeCombo->count() / 3));
    else
        sizeCombo->setCurrentIndex(sizeIndex);*/
}

void MainWindow::bookTicket()
{
    if (_currSeat == QString::null) return;
    ticketWidget = new TicketWidget(trainCombo->currentText().toInt(),
                                    _route, wagonCombo->currentText().toInt(), _currSeat.toInt(), _date);
    connect(ticketWidget, SIGNAL(seatBooked()), this, SLOT(fillSeat()));
    ticketWidget->show();
}

void MainWindow::fillSeat()
{
    QMessageBox msgBox;
    if (_currSeat != QString::null)
        msgBox.setText(_currSeat);
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
