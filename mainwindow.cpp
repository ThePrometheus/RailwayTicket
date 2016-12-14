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

MainWindow::MainWindow(const QVector<QString>& availableTrains) : _availableTrains(availableTrains)
{
    QWidget *centralWidget = new QWidget;

    QLabel *fontLabel = new QLabel(tr("Train:"));
    trainCombo = new QComboBox;
    QLabel *wagonLabel = new QLabel(tr("Wagon:"));
    wagonCombo = new QComboBox;

    scrollArea = new QScrollArea;
    seatWidget = new SeatWidget;
    scrollArea->setWidget(seatWidget);

    //findTrain(trainCombo->currentFont());
  // findSeats(wagonCombog->currentFont());

    bookButton = new QPushButton(tr("&Book seat"));

    connect(trainCombo, SIGNAL(currentIndexChanged(QFont)),
            this, SLOT(findTrain(QFont)));
   // connect(trainCombo, SIGNAL(currentIndexChanged(QFont)),
            //seatWidget, SLOT(updateFont(QFont)));
    connect(wagonCombo, SIGNAL(currentIndexChanged(QString)),
            seatWidget, SLOT(updateSize(QString)));
    connect(wagonCombo, SIGNAL(currentIndexChanged(QString)),
            seatWidget, SLOT(findSeats(QString)));

    connect(bookButton, SIGNAL(clicked()), this, SLOT(fillSeat()));

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(fontLabel);
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
}

void MainWindow::findTrain(const QString &font)
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

void MainWindow::fillSeat()
{
    /*lineEdit->insert(seat);*/
    QMessageBox msgBox;
    msgBox.setText("test");
    msgBox.exec();
}

/*#ifndef QT_NO_CLIPBOARD
void MainWindow::updateClipboard()
{
    clipboard->setText(lineEdit->text(), QClipboard::Clipboard);
    clipboard->setText(lineEdit->text(), QClipboard::Selection);
}
#endif*/
