#ifndef TASKITEM_H
#define TASKITEM_H

#endif // TASKITEM_H
#include <QObject>
#include <QGraphicsItem>
#include "scheduleview.h"
class TaskItem:public QGraphicsItem
{
public:
    explicit TaskItem(ScheduleView *sheduleView,QString message);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ScheduleView* graph;
    QString info;
    float width;
    float height;
};
