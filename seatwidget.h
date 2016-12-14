#ifndef SEATWIDGET_H
#define SEATWIDGET_H

#include <QWidget>
#include <QFont>
#include <QSize>
#include <QMouseEvent>
#include <QString>

class SeatWidget : public QWidget
{
    Q_OBJECT

public:
    SeatWidget(QWidget *parent = 0);
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void updateFont(const QFont &font);
    void updateSize(const QString &fontSize);
    void updateStyle(const QString &fontStyle);
    void updateFontMerging(bool enable);

signals:
    void seatSelected(const QString &character);

protected:
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QFont displayFont;
    int columns;
    int lastKey;
    int squareSize;
};
#endif // SEATWIDGET_H
