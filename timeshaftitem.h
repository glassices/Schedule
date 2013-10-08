#ifndef TIMESHAFTITEM_H
#define TIMESHAFTITEM_H

#include <QObject>
#include <QGraphicsItem>

class TimeShaftItem : public QGraphicsItem
{
public:
    explicit TimeShaftItem();
    QRectF boundingRect() const;
    QPainterPath shape() const;
};

#endif // TIMESHAFTITEM_H
