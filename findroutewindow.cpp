#include "findroutewindow.h"
#include <QGridLayout>
#include <QMessageBox>
#include "stops.h"

FindRouteWindow::FindRouteWindow(QWidget *parent)
    : QWidget(parent), _rdb("c:/tmpdata/routes.json")
{
    setupModel();

    departLabel = new QLabel(tr("&Depart from:"));
    departEdit = new QLineEdit();
    destinationLabel = new QLabel(tr("&Arrive at:"));
    destinationEdit = new QLineEdit();
    dateLabel = new QLabel(tr("&Date of departure:"));
    dateEdit = new QLineEdit();
    findButton = new QPushButton(tr("&Find a train"));
   // previousButton = new QPushButton(tr("&Previous"));

    departLabel->setBuddy(departEdit);
    destinationLabel->setBuddy(destinationEdit);
    dateLabel->setBuddy(dateEdit);
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
    layout->addWidget(dateLabel, 3, 0, 1, 1);
    layout->addWidget(dateEdit, 3, 1, 1, 1);
    layout->addWidget(findButton, 0, 3, 1, 1);
   // layout->addWidget(typeLabel, 3, 0, 1, 1);
   // layout->addWidget(typeComboBox, 3, 1, 1, 1);
    setLayout(layout);

    setWindowTitle(tr("Find the train"));
    mapper->toFirst();
}

void FindRouteWindow::handleRoute() {
    QString from(departEdit->text());
    QString to(destinationEdit->text());
    QString on(dateEdit->text().toInt());
    // When the db works
    // const QVector<QSharedPointer<Route>> routes(_rdb.findRoutes(from, to));
   /* QVector<QSharedPointer<Stops>> st(1);
    Stops s(10, to);
    QSharedPointer<Stops> sp(&s);
    st.append(sp);
    Route r (from,1,2,st);
    QSharedPointer<Route> rp(&r);
    QVector<QSharedPointer<Route>> routes(1);

    routes.append(rp);

    _availableTrains.clear();
    foreach (const QSharedPointer<Route> route, routes) {
        qDebug() << route->findByDate(10);
        _availableTrains.append(route->findByDate(10));
        qDebug() << "in handler";
    }*/

    if (true) {
        QVector<QString> v(2);
        v.append(QString("test1"));
        v.append(QString("test2"));
        window = new MainWindow(v);
        window->show();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Sorry, there are no available trains at the moment.");
        msgBox.exec();
    }
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
