#include "timeshaftitem.h"
#include "sdk.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
<<<<<<< HEAD
#include <QGraphicsSceneMouseEvent>
=======
#include <QString>
>>>>>>> develop

TimeShaftItem::TimeShaftItem(ScheduleView *sheduleView) :
    graph(sheduleView)
{
<<<<<<< HEAD
    setFlag(ItemIsSelectable);
    //setAcceptHoverEvents(true);
    setZValue(-1);
    ratio = 1;
    isPressed = 0;
    startPosition = 0;
    scaleRatio = 1;
=======
    setZValue(-1);
    ratio = exp(0.1)-1;
>>>>>>> develop
}
QRectF TimeShaftItem::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-gls::TIMER_SHAFT_WIDTH / 2 - adjust, -gls::TIMER_SHAFT_HEIGHT / 2 - adjust, gls::TIMER_SHAFT_WIDTH + adjust * 2, gls::TIMER_SHAFT_HEIGHT + adjust * 2);
}
QPainterPath TimeShaftItem::shape() const
{
    QPainterPath path;
    path.addRect(-gls::TIMER_SHAFT_WIDTH / 2, -gls::TIMER_SHAFT_HEIGHT / 2, gls::TIMER_SHAFT_WIDTH, gls::TIMER_SHAFT_HEIGHT);
    return path;
}
void TimeShaftItem::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget *)
{
    painter->translate(-gls::TIMER_SHAFT_LENGTH / 2, 0);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::NoBrush);
    //qDebug() << gls::TIMER_SHAFT_LENGTH << endl;
    painter->drawLine(0, 0, gls::TIMER_SHAFT_LENGTH, 0);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawLine(gls::TIMER_SHAFT_LENGTH, 0, gls::TIMER_SHAFT_LENGTH-10, -3);
    painter->drawLine(gls::TIMER_SHAFT_LENGTH, 0, gls::TIMER_SHAFT_LENGTH-10, +3);
    painter->setRenderHint(QPainter::Antialiasing, false);
    QFont font = painter->font();
    font.setWeight(0);
    font.setPointSize(10);
    painter->setFont(font);
    int previous = -100;
<<<<<<< HEAD
    for (int i = 0; i < 20; i++) {
        painter->drawLine(i * 30, 0, i * 30, 5);
        painter->drawText(QPointF(i * 30 - 3, 15), QString("%1h").arg((int)(startPosition + (exp(i * 0.1) - 1) / (exp(1 * 0.1) - 1) * 6 * ratio)));
    }
}
void TimeShaftItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isPressed = true;
        //qDebug() << 1 << endl;
    }
    QGraphicsItem::mousePressEvent(event);
}
void TimeShaftItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isPressed = false;
        //qDebug() << 2 << endl;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}
void TimeShaftItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << 2 << endl;
    if (! isPressed) return;
    QPointF delta = event->pos() - event->lastPos();
    startPosition -= delta.x();
    if (startPosition < 0) startPosition = 0;
    update();
    QGraphicsItem::mouseMoveEvent(event);
}
void TimeShaftItem::mactransform(int delta)
{
    // This is to support mac touchpad
    startPosition -= delta;
    if (startPosition < 0) startPosition = 0;
    update();
}
void TimeShaftItem::zoom(int delta, QPointF scenePosition)
{
    qreal cursor_x = mapFromScene(scenePosition).x() + gls::TIMER_SHAFT_LENGTH / 2;
    if (cursor_x < 0) cursor_x = 0;
    if (cursor_x > gls::TIMER_SHAFT_LENGTH) cursor_x = gls::TIMER_SHAFT_LENGTH;

    qreal pre_ratio = ratio;
    ratio *= exp(delta * 0.01);
    if (ratio > 1) ratio = 1;
    startPosition -= (exp(cursor_x / 300)-1) / (exp(0.1) - 1) * 6 * (ratio - pre_ratio);
    if (startPosition < 0) startPosition = 0;
    update();
=======
    for (int i = 0; i < 80; i++) {
        int drawPosition = qRound(log(i * ratio + 1) * 10 * 30);
        if (drawPosition - previous >= 25) {
            if (i > 4 && i % 4 != 0) continue;
            if (i == 3) continue;
            painter->drawLine(drawPosition, 0, drawPosition, 5);
            if (i == 0)
                painter->drawText(QPointF(drawPosition-3, 15), QString("0"));
            else if (i % 4 == 0)
                painter->drawText(QPointF(drawPosition-3, 15), QString("%1d").arg(i / 4));
            else
                painter->drawText(QPointF(drawPosition-3, 15), QString("%1h").arg(i * 6));
            previous = drawPosition;
        }
    }
>>>>>>> develop
}
