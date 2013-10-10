#include "timeshaftitem.h"
#include "sdk.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QTime>
#include <QDate>

TimeShaftItem::TimeShaftItem(ScheduleView *sheduleView) :
    graph(sheduleView)
{
    setFlag(ItemIsSelectable);
    //setAcceptHoverEvents(true);
    setZValue(-1);
    ratio = 1;
    isPressed = 0;
    startPosition = 0;
    scaleRatio = 1;
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
    painter->drawLine(0, 5, 0, -5);
    painter->drawLine(gls::TIMER_SHAFT_LENGTH, 0, gls::TIMER_SHAFT_LENGTH-10, -3);
    painter->drawLine(gls::TIMER_SHAFT_LENGTH, 0, gls::TIMER_SHAFT_LENGTH-10, +3);
    painter->setRenderHint(QPainter::Antialiasing, false);
    QFont font = painter->font();
    font.setWeight(0);
    font.setPointSize(10);
    painter->setFont(font);

    QTime time = QTime::currentTime();
    QTime ending = QTime(23, 59, 59);
    QDate date = QDate::currentDate();
    qreal remainHours = (qreal)(time.secsTo(ending) + 1) / 60 / 60;
    QDate tempDate(date);
    painter->drawText(QPointF(0, -10), QString("ratio is %1, %2h %3m %4s %5y %6m %7d").arg(ratio).arg(time.hour()).arg(time.minute()).arg(time.second()).arg(date.year()).arg(date.month()).arg(date.day()));
    int previous = -100;
    for (int h = remainHours; ; h += 24) {
        tempDate = tempDate.addDays(1);
        if (h + 25 < startPosition) {
            int ret = (startPosition - h) / 24;
            h += 24 * ret;
            tempDate = tempDate.addDays(ret);
        }
        if (h >= startPosition) {
            int x = qRound(log((h - startPosition) / ratio / 6 * (exp(0.1) - 1) + 1) * 300);
            if (x > gls::TIMER_SHAFT_LENGTH - 10) break;
            if (x - previous > 30) {
                painter->drawLine(x, 0, x, 5);
                painter->drawText(QPointF(x - 10, 15), QString("%1.%2").arg(tempDate.month()).arg(tempDate.day()));
                previous = x;
            }
        }
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
}
