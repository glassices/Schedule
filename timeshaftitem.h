#ifndef TIMESHAFTITEM_H
#define TIMESHAFTITEM_H

#include <QObject>
#include <QGraphicsItem>
#include "scheduleview.h"

class TimeShaftItem : public QGraphicsItem
{
public:
    explicit TimeShaftItem(ScheduleView *sheduleView);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    qreal ratio;
    ScheduleView *graph;
};

#endif // TIMESHAFTITEM_H
