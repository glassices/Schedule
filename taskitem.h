#ifndef TASKITEM_H
#define TASKITEM_H

#endif // TASKITEM_H
#include <QObject>
#include <QGraphicsItem>
#include "scheduleview.h"
class TaskItem:public QGraphicsItem
{
    explicit TaskItem(ScheduleView *sheduleView);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    ScheduleView* graph;
};
