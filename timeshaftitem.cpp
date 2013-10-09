#include "timeshaftitem.h"
#include "sdk.h"
#include <QPainter>

TimeShaftItem::TimeShaftItem(ScheduleView *sheduleView) :
    graph(sheduleView)
{
    setZValue(-1);
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
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkBlue);
    painter->drawRect(-100, -5, 200, 10);
}
