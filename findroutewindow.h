#ifndef FINDROUTEWINDOW_H
#define FINDROUTEWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QTextEdit>
#include <QDataWidgetMapper>
#include "routedb.h"

class QComboBox;
class QDataWidgetMapper;
class QLabel;
class QLineEdit;
class QPushButton;
class QStandardItemModel;
class QStringListModel;
class QTextEdit;

class FindRouteWindow : public QWidget
{
    Q_OBJECT

public:
    FindRouteWindow(QWidget *parent = 0);

private slots:
    void updateButtons(int row);

private:
    void setupModel();
    void handleRoute();

    QLabel *departLabel;
    QLabel *destinationLabel;
    QLabel *typeLabel;
    QLineEdit *departEdit;
    QLineEdit *destinationEdit;
   // QComboBox *typeComboBox;
    QPushButton *findButton;
   // QPushButton *previousButton;

    QStandardItemModel *model;
   // QStringListModel *typeModel;
    QDataWidgetMapper *mapper;

    RouteDb _rdb;
};


#endif // FINDROUTEWINDOW_H
