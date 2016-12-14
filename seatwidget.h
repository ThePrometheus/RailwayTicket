#ifndef SEATWIDGET_H
#define SEATWIDGET_H

#include <QWidget>
#include <QFont>
#include <QSize>
#include <QMouseEvent>
#include <QString>
#include <QVector>

class SeatWidget : public QWidget
{
    Q_OBJECT

public:
    SeatWidget(const QVector<QString> &seats, QWidget *parent = 0);
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
  //  void updateFont(const QString &font);
    void updateSeats(const QString &seats);
   // void updateStyle(const QString &fontStyle);
   // void updateFontMerging(bool enable);

signals:
    void seatSelected(const QString &seat);

protected:
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QFont displayFont;
    int columns;
    int lastKey;
    int squareSize;

    // for debug
    QVector<QString> _seats;
};
#endif // SEATWIDGET_H
