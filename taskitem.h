#ifndef TASKITEM_H
#define TASKITEM_H

#include <QObject>
#include <QGraphicsItem>
#include "scheduleview.h"
#include <QDateTime>

class TaskItem:public QGraphicsItem
{
public:
    explicit TaskItem(ScheduleView *sheduleView, QString message, QDateTime dt);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
<<<<<<< HEAD
    ScheduleView* graph;
    QString info;
    float width;
    float height;
=======
private:
    ScheduleView *graph;
    QString info;
    int width;
    QDateTime datetime;
>>>>>>> origin/Glassices
};

#endif // TASKITEM_H
