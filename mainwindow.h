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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // vector of strings while the data model isn't working properly
    MainWindow(const QVector<QString>& availableTrains);

public slots:
    void findWagons(const QString &font);
    void findSeats(const QString &font);
    void fillSeat();
private:
    void init();

    SeatWidget *seatWidget;
    QComboBox *trainCombo;
    QComboBox *wagonCombo;
   // QLineEdit *lineEdit;
    QScrollArea *scrollArea;
   // QCheckBox *fontMerging;
    QPushButton *bookButton;
    const QVector<QString>& _availableTrains;
};

#endif // MAINWINDOW_H
