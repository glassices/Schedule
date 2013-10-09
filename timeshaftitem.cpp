#include "timeshaftitem.h"
#include "sdk.h"
#include <QPainter>
#include <QDebug>
#include <cmath>

TimeShaftItem::TimeShaftItem(ScheduleView *sheduleView) :
    graph(sheduleView)
{
    setZValue(-1);
    ratio = exp(0.1)-1;
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
    for (int i = 0; i < 80; i++) {
        int drawPosition = qRound(log(i * ratio + 1) * 10 * 30);
        painter->drawLine(drawPosition, 0, drawPosition, 5);
    }
}
