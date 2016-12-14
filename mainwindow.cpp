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

MainWindow::MainWindow()
{
    QWidget *centralWidget = new QWidget;

    QLabel *fontLabel = new QLabel(tr("Train:"));
    fontCombo = new QFontComboBox;
    /*QLabel *sizeLabel = new QLabel(tr("Size:"));
    sizeCombo = new QComboBox;
    QLabel *styleLabel = new QLabel(tr("Style:"));
    styleCombo = new QComboBox;
    QLabel *fontMergingLabel = new QLabel(tr("Automatic Font Merging:"));
    fontMerging = new QCheckBox;
    fontMerging->setChecked(true);*/

    scrollArea = new QScrollArea;
    seatWidget = new SeatWidget;
    scrollArea->setWidget(seatWidget);

    findStyles(fontCombo->currentFont());
    findSizes(fontCombo->currentFont());

   /* lineEdit = new QLineEdit;
#ifndef QT_NO_CLIPBOARD*/
    clipboardButton = new QPushButton(tr("&Book seat"));

    /*clipboard = QApplication::clipboard();
#endif*/

    connect(fontCombo, SIGNAL(currentFontChanged(QFont)),
            this, SLOT(findStyles(QFont)));
    connect(fontCombo, SIGNAL(currentFontChanged(QFont)),
            this, SLOT(findSizes(QFont)));
    connect(fontCombo, SIGNAL(currentFontChanged(QFont)),
            seatWidget, SLOT(updateFont(QFont)));

//#ifndef QT_NO_CLIPBOARD
    connect(clipboardButton, SIGNAL(clicked()), this, SLOT(fillSeat()));
//#endif
   // connect(fontMerging, SIGNAL(toggled(bool)), seatWidget, SLOT(updateFontMerging(bool)));*

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(fontLabel);
    controlsLayout->addWidget(fontCombo, 1);
   /* controlsLayout->addWidget(sizeLabel);
    controlsLayout->addWidget(sizeCombo, 1);
    controlsLayout->addWidget(styleLabel);
    controlsLayout->addWidget(styleCombo, 1);
    controlsLayout->addWidget(fontMergingLabel);
    controlsLayout->addWidget(fontMerging, 1);*/
    controlsLayout->addStretch(1);

    QHBoxLayout *lineLayout = new QHBoxLayout;
   // lineLayout->addWidget(lineEdit, 1);
    lineLayout->addSpacing(12);
//#ifndef QT_NO_CLIPBOARD
    lineLayout->addWidget(clipboardButton);
//#endif

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addLayout(controlsLayout);
    centralLayout->addWidget(scrollArea, 1);
    centralLayout->addSpacing(4);
    centralLayout->addLayout(lineLayout);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("Buy the Ticket"));
}

void MainWindow::findStyles(const QFont &font)
{
    QFontDatabase fontDatabase;
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

void MainWindow::findSizes(const QFont &font)
{
    QFontDatabase fontDatabase;
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
