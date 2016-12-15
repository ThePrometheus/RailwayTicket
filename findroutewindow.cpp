#include "findroutewindow.h"
#include <QGridLayout>
#include <QMessageBox>
#include "stops.h"
#include <QRegExp>

FindRouteWindow::FindRouteWindow(QWidget *parent)
    : QWidget(parent), _rdb(QString("c:/tmpdata/routes.json"), QString("c:/tmpdata/tickets.json"))
{
    setupModel();

    departLabel = new QLabel(tr("&Depart from:"));
    departEdit = new QLineEdit();
    destinationLabel = new QLabel(tr("&Arrive at:"));
    destinationEdit = new QLineEdit();
    dateLabel = new QLabel(tr("&Date of departure:"));
    dateEdit = new QLineEdit();
    findButton = new QPushButton(tr("&Find a train"));

    departLabel->setBuddy(departEdit);
    destinationLabel->setBuddy(destinationEdit);
    dateLabel->setBuddy(dateEdit);
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(departEdit, 0);
    mapper->addMapping(destinationEdit, 1);

    connect(findButton, &QAbstractButton::clicked,
            this, &FindRouteWindow::handleRoute);
    connect(mapper, &QDataWidgetMapper::currentIndexChanged,
            this, &FindRouteWindow::updateButtons);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(departLabel, 0, 0, 1, 1);
    layout->addWidget(departEdit, 0, 1, 1, 1);
    layout->addWidget(destinationLabel, 1, 0, 1, 1);
    layout->addWidget(destinationEdit, 1, 1, 2, 1);
    layout->addWidget(dateLabel, 3, 0, 1, 1);
    layout->addWidget(dateEdit, 3, 1, 1, 1);
    layout->addWidget(findButton, 0, 3, 1, 1);
    setLayout(layout);

    setWindowTitle(tr("Find the train"));
    mapper->toFirst();
}

void FindRouteWindow::handleRoute() {

    QString from(departEdit->text());
    QString to(destinationEdit->text());
    QString on(dateEdit->text());
    QRegExp re("\\d*");
    if (!re.exactMatch(on)) {
        QMessageBox msgBox;
        msgBox.setText("Fill in the date correctly.");
        msgBox.exec();
        return;
    }
    qDebug() << from << " " << to << " " << on;
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

    if (!from.isEmpty() && !to.isEmpty() && !on.isEmpty()) {
        const QVector<const Train*> f(_rdb.findTrains(from, to, on.toInt()));
        QVector<QString> v(2);
        v.append(QString("1"));
        v.append(QString("2"));
        window = new MainWindow(0,on.toInt(),f);
        window->show();
        return;
    } else {
        QMessageBox msgBox;
        msgBox.setText("Fill out the search form, please.");
        msgBox.exec();
    }
}

void FindRouteWindow::setupModel()
{
    model = new QStandardItemModel(5, 3, this);
    QStringList departures;
    departures << _rdb.findRoute(0).getDepartStation();
    QStringList destinations;
    destinations << _rdb.findRoute(0).getArrivalStations().at(0);

    for (int row = 0; row < 1; ++row) {
        QStandardItem *item = new QStandardItem(departures[row]);
        model->setItem(row, 0, item);
        item = new QStandardItem(destinations[row]);
        model->setItem(row, 1, item);
    }
}

void FindRouteWindow::updateButtons(int row)
{
    findButton->setEnabled(row < model->rowCount() - 1);
}
