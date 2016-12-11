#include "findroutewindow.h"
#include <QGridLayout>
#include <QMessageBox>

FindRouteWindow::FindRouteWindow(QWidget *parent)
    : QWidget(parent), _rdb("c:/tmpdata/routes.json")
{
    setupModel();

    departLabel = new QLabel(tr("&Depart from:"));
    departEdit = new QLineEdit();
    destinationLabel = new QLabel(tr("&Arrive at:"));
    destinationEdit = new QLineEdit();
   // typeLabel = new QLabel(tr("&Type:"));
   // typeComboBox = new QComboBox();
    findButton = new QPushButton(tr("&Find a train"));
   // previousButton = new QPushButton(tr("&Previous"));

    departLabel->setBuddy(departEdit);
    destinationLabel->setBuddy(destinationEdit);
   // typeLabel->setBuddy(typeComboBox);

   // typeComboBox->setModel(typeModel);

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(departEdit, 0);
    mapper->addMapping(destinationEdit, 1);
   // mapper->addMapping(typeComboBox, 2, "currentIndex");

    //connect(previousButton, &QAbstractButton::clicked,
            //mapper, &QDataWidgetMapper::toPrevious);
    connect(findButton, &QAbstractButton::clicked,
            this, &FindRouteWindow::handleRoute);
    connect(mapper, &QDataWidgetMapper::currentIndexChanged,
            this, &FindRouteWindow::updateButtons);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(departLabel, 0, 0, 1, 1);
    layout->addWidget(departEdit, 0, 1, 1, 1);
   // layout->addWidget(previousButton, 0, 2, 1, 1);
    layout->addWidget(destinationLabel, 1, 0, 1, 1);
    layout->addWidget(destinationEdit, 1, 1, 2, 1);
    layout->addWidget(findButton, 1, 2, 1, 1);
   // layout->addWidget(typeLabel, 3, 0, 1, 1);
   // layout->addWidget(typeComboBox, 3, 1, 1, 1);
    setLayout(layout);

    setWindowTitle(tr("Find the train"));
    mapper->toFirst();
}

void FindRouteWindow::handleRoute() {
    QMessageBox msgBox;
    msgBox.setText("Sorry, there's no such route available.");
    msgBox.exec();
}

void FindRouteWindow::setupModel()
{
    QStringList items;
    items << tr("Home") << tr("Work") << tr("Other");
    //typeModel = new QStringListModel(items, this);

    model = new QStandardItemModel(5, 3, this);
    QStringList departures;
    departures << "Input the station name";
    QStringList destinations;
    destinations << "Input the station name";

  //  QStringList types;
  //  types << "0" << "1" << "2" << "0" << "2";

    for (int row = 0; row < 1; ++row) {
        QStandardItem *item = new QStandardItem(departures[row]);
        model->setItem(row, 0, item);
        item = new QStandardItem(destinations[row]);
        model->setItem(row, 1, item);
       // item = new QStandardItem(types[row]);
       // model->setItem(row, 2, item);
    }
}

void FindRouteWindow::updateButtons(int row)
{
   // previousButton->setEnabled(true);
    findButton->setEnabled(row < model->rowCount() - 1);
}
