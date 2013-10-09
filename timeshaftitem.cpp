#include "timeshaftitem.h"
#include "sdk.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
<<<<<<< HEAD
=======
#include <QString>
>>>>>>> Glassices

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
<<<<<<< HEAD
    for (int i = 0; i < 80; i++) {
        int drawPosition = qRound(log(i * ratio + 1) * 10 * 30);
        painter->drawLine(drawPosition, 0, drawPosition, 5);
=======
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawLine(gls::TIMER_SHAFT_LENGTH, 0, gls::TIMER_SHAFT_LENGTH-10, -3);
    painter->drawLine(gls::TIMER_SHAFT_LENGTH, 0, gls::TIMER_SHAFT_LENGTH-10, +3);
    painter->setRenderHint(QPainter::Antialiasing, false);
    QFont font = painter->font();
    font.setWeight(0);
    font.setPointSize(10);
    painter->setFont(font);
    int previous = -100;
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
>>>>>>> Glassices
    }
}
