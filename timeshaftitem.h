#ifndef TIMESHAFTITEM_H
#define TIMESHAFTITEM_H

#include <QObject>
#include <QGraphicsItem>
#include "scheduleview.h"

class TimeShaftItem : public QGraphicsItem
{
public:
    explicit TimeShaftItem(ScheduleView *scheduleView);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
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

    int calcPosition(qreal hour);
    void subDraw(QPainter *painter, qreal H, qreal previous, qreal current, int flag, int curHour, int curMinute = 60);
};

#endif // TIMESHAFTITEM_H
