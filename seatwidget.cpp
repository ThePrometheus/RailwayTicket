#include <QtWidgets>
#include <QDebug>

#include "seatwidget.h"

SeatWidget::SeatWidget(const QVector<QString> &seats, QWidget *parent)
    : QWidget(parent), _seats(seats)
{
    squareSize = 24;
    columns = 16;
    lastKey = -1;
    setMouseTracking(true);
}

/*void SeatWidget::updateFont(const QString &font)
{
    /*displayFont.setFamily(font.family());
    squareSize = qMax(24, QFontMetrics(displayFont).xHeight() * 3);
    adjustSize();
    update();
}*/

void SeatWidget::updateSeats(const QString &seats)
{
    adjustSize();
    update();
}

/*void SeatWidget::updateStyle(const QString &fontStyle)
{
    QFontDatabase fontDatabase;
    const QFont::StyleStrategy oldStrategy = displayFont.styleStrategy();
    displayFont = fontDatabase.font(displayFont.family(), fontStyle, displayFont.pointSize());
    displayFont.setStyleStrategy(oldStrategy);
    squareSize = qMax(24, QFontMetrics(displayFont).xHeight() * 3);
    adjustSize();
    update();
}

void SeatWidget::updateFontMerging(bool enable)
{
    if (enable)
        displayFont.setStyleStrategy(QFont::PreferDefault);
    else
        displayFont.setStyleStrategy(QFont::NoFontMerging);
    adjustSize();
    update();
}*/

QSize SeatWidget::sizeHint() const
{
    return QSize(columns*squareSize, (65536/columns)*squareSize);
}

void SeatWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint widgetPosition = mapFromGlobal(event->globalPos());
    uint key = (widgetPosition.y()/squareSize)*columns + widgetPosition.x()/squareSize;

    QString text = QString::fromLatin1("<p>Character: <span style=\"font-size: 24pt; font-family: %1\">").arg(displayFont.family())
                  + QChar(key)
                  + QString::fromLatin1("</span><p>Value: 0x")
                  + QString::number(key, 16);
    QToolTip::showText(event->globalPos(), text, this);
}

void SeatWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastKey = (event->y()/squareSize)*columns + event->x()/squareSize;
        if (QChar(lastKey).category() != QChar::Other_NotAssigned)
            emit seatSelected(QString(QChar(lastKey)));
        update();
    }
    else
        QWidget::mousePressEvent(event);
}

void SeatWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    squareSize = qMax(24, QFontMetrics(displayFont).xHeight() * 3);
    painter.fillRect(event->rect(), QBrush(Qt::white));
    painter.setFont(displayFont);

    QRect redrawRect = event->rect();
    int beginRow = redrawRect.top()/squareSize;
    int endRow = redrawRect.bottom()/squareSize;
    int beginColumn = redrawRect.left()/squareSize;
    int endColumn = redrawRect.right()/squareSize;

    painter.setPen(QPen(Qt::gray));
    for (int row = beginRow; row <= endRow; ++row) {
        for (int column = beginColumn; column <= endColumn; ++column) {
            painter.drawRect(column*squareSize, row*squareSize, squareSize, squareSize);
        }
    }

    qDebug() << beginRow << " " << endRow;
    qDebug() << beginColumn << " " << endColumn;

    QFontMetrics fontMetrics(displayFont);
    painter.setPen(QPen(Qt::black));

    for (size_t row = beginRow; row <= endRow; ++row) {

        for (size_t column = beginColumn; column <= endColumn; ++column) {

            int key = row*columns + column;
            if (key >= _seats.size()) return;
            const QString& seat = _seats.at(key);
            painter.setClipRect(column*squareSize, row*squareSize, squareSize, squareSize);

            if (key == lastKey)
                painter.fillRect(column*squareSize + 1, row*squareSize + 1, squareSize, squareSize, QBrush(Qt::red));

            painter.drawText(column*squareSize + (squareSize / 2) - fontMetrics.width(QChar(key))/2,
                             row*squareSize + 4 + fontMetrics.ascent(),
                             seat);
        }
    }
}
