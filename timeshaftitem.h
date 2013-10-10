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
<<<<<<< HEAD
    void mactransform(int delta);
    void zoom(int delta, QPointF scenePosition);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    //void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    //void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    //void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
private:
    bool isPressed;
    qreal ratio;
    qreal startPosition; // Start position of the timer shaft
    qreal scaleRatio;
    ScheduleView *graph; // The ratio of scaling
=======
private:
    qreal ratio;
    ScheduleView *graph;
>>>>>>> develop
};

#endif // TIMESHAFTITEM_H
