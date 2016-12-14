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
#include "seatwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void findStyles(const QFont &font);
    void findSizes(const QFont &font);
    void fillSeat();
/*#ifndef QT_NO_CLIPBOARD
    void updateClipboard();
#endif*/

private:
    SeatWidget *seatWidget;
/*#ifndef QT_NO_CLIPBOARD
    QClipboard *clipboard;
#endif*/
    //QComboBox *styleCombo;
    //QComboBox *sizeCombo;
    QFontComboBox *fontCombo;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea;
    QCheckBox *fontMerging;
    QPushButton *clipboardButton;
};

#endif // MAINWINDOW_H
