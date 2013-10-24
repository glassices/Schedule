#include "timeshaftitem.h"
#include "sdk.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QTime>
#include <QDate>

TimeShaftItem::TimeShaftItem(ScheduleView *scheduleView) :
    graph(scheduleView)
{
    Q_UNUSED(graph);

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
void subDraw(QPainter *painter, qreal &startPosition, qreal &ratio, qreal H, qreal previous, qreal current, int flag, int curHour, int curMinute = 60)
{
    if (current - previous <= gls::TIMER_SHAFT_DELTA * 2) return;
    if (flag == 0) {
        // draw 12:00
        qreal h = H - 12;
        int x = qRound(log((h - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        if (x - previous > gls::TIMER_SHAFT_DELTA && current - x > gls::TIMER_SHAFT_DELTA && x >= 0 && x <= gls::TIMER_SHAFT_LENGTH - 10) {
            painter->drawLine(x, 0, x, 5);
            painter->drawText(QPointF(x - 10, 15), QString("12:00"));
        }
        subDraw(painter, startPosition, ratio, h, previous, x, 1, curHour -  12);
        subDraw(painter, startPosition, ratio, H, x, current, 1, curHour);
    }
    else if (flag == 1) {
        // draw 6:00
        qreal h = H - 6;
        int x = qRound(log((h - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        if (x - previous > gls::TIMER_SHAFT_DELTA && current - x > gls::TIMER_SHAFT_DELTA && x >= 0 && x <= gls::TIMER_SHAFT_LENGTH - 10) {
            painter->drawLine(x, 0, x, 5);
            painter->drawText(QPointF(x - 10, 15), QString("%1:00").arg(curHour - 6));
        }
        subDraw(painter, startPosition, ratio, h, previous, x, 2, curHour - 6);
        subDraw(painter, startPosition, ratio, H, x, current, 2, curHour);
    }
    else if (flag == 2) {
        // draw 3:00
        qreal h = H - 3;
        int x = qRound(log((h - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        if (x - previous > gls::TIMER_SHAFT_DELTA && current - x > gls::TIMER_SHAFT_DELTA && x >= 0 && x <= gls::TIMER_SHAFT_LENGTH - 10) {
            painter->drawLine(x, 0, x, 5);
            painter->drawText(QPointF(x - 10, 15), QString("%1:00").arg(curHour - 3));
        }
        subDraw(painter, startPosition, ratio, h, previous, x, 3, curHour - 3);
        subDraw(painter, startPosition, ratio, H, x, current, 3, curHour);
    }
    else if (flag == 3) {
        // draw 1:00 and 2:00
        qreal h1 = H - 2;
        qreal h2 = H - 1;
        int x1 = qRound(log((h1 - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        int x2 = qRound(log((h2 - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        //qDebug() << previous << ' ' << current << ' ' << x1 << ' ' << x2 << endl;
        if (x1 - previous > gls::TIMER_SHAFT_DELTA && x2 - x1 > gls::TIMER_SHAFT_DELTA && current - x2 > gls::TIMER_SHAFT_DELTA) {
            if (x1 >= 0 && x1 <= gls::TIMER_SHAFT_LENGTH - 10) {
                painter->drawLine(x1, 0, x1, 5);
                painter->drawText(QPointF(x1 - 10, 15), QString("%1:00").arg(curHour - 2));
            }
            if (x2 >= 0 && x2 <= gls::TIMER_SHAFT_LENGTH - 10) {
                painter->drawLine(x2, 0, x2, 5);
                painter->drawText(QPointF(x2 - 10, 15), QString("%1:00").arg(curHour - 1));
            }
        }
        subDraw(painter, startPosition, ratio, h1, previous, x1, 4, curHour - 2);
        subDraw(painter, startPosition, ratio, h2, x1, x2, 4, curHour - 1);
        subDraw(painter, startPosition, ratio, H, x2, current, 4, curHour);
    }
    else if (flag  == 4) {
        // draw 0:30
        qreal h = H - 0.5;
        int x = qRound(log((h - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        if (x - previous > gls::TIMER_SHAFT_DELTA && current - x > gls::TIMER_SHAFT_DELTA && x >= 0 && x <= gls::TIMER_SHAFT_LENGTH - 10) {
            painter->drawLine(x, 0, x, 5);
            painter->drawText(QPointF(x - 10, 15), QString("%1:30").arg(curHour - 1));
        }
        subDraw(painter, startPosition, ratio, h, previous, x, 5, curHour, 30);
        subDraw(painter, startPosition, ratio, H, x, current, 5, curHour, 60);
    }
    else if (flag == 5) {
        // draw 0:15
        qreal h = H - 0.25;
        int x = qRound(log((h - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        if (x - previous > gls::TIMER_SHAFT_DELTA && current - x > gls::TIMER_SHAFT_DELTA && x >= 0 && x <= gls::TIMER_SHAFT_LENGTH - 10) {
            painter->drawLine(x, 0, x, 5);
            painter->drawText(QPointF(x - 10, 15), QString("%1:%2").arg(curHour - 1).arg(curMinute - 15));
        }
        subDraw(painter, startPosition, ratio, h, previous, x, 6, curHour, curMinute - 15);
        subDraw(painter, startPosition, ratio, H, x, current, 6, curHour, curMinute);
    }
    else if (flag == 6) {
        // draw 0:05 && 0:10
        qreal h1 = H - 0.25 * 2 / 3;
        qreal h2 = H - 0.25 / 3;
        int x1 = qRound(log((h1 - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        int x2 = qRound(log((h2 - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        if (x1 - previous > gls::TIMER_SHAFT_DELTA && x2 - x1 > gls::TIMER_SHAFT_DELTA && current - x2 > gls::TIMER_SHAFT_DELTA) {
            if (x1 >= 0 && x1 <= gls::TIMER_SHAFT_LENGTH - 10) {
                painter->drawLine(x1, 0, x1, 5);
                if (curMinute - 10 == 5)
                    painter->drawText(QPointF(x1 - 10, 15), QString("%1:05").arg(curHour - 1));
                else
                    painter->drawText(QPointF(x1 - 10, 15), QString("%1:%2").arg(curHour - 1).arg(curMinute - 10));
            }
            if (x2 >= 0 && x2 <= gls::TIMER_SHAFT_LENGTH - 10) {
                painter->drawLine(x2, 0, x2, 5);
                painter->drawText(QPointF(x2 - 10, 15), QString("%1:%2").arg(curHour - 1).arg(curMinute - 5));
            }
        }
        subDraw(painter, startPosition, ratio, h1, previous, x1, 7, curHour, curMinute - 10);
        subDraw(painter, startPosition, ratio, h2, x1, x2, 7, curHour, curMinute - 5);
        subDraw(painter, startPosition, ratio, H, x2, current, 7, curHour, curMinute);
    }
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

    painter->drawText(QPointF(0, -10), QString("ratio is %1, %2h %3m %4s %5y %6m %7d").arg(ratio).arg(time.hour()).arg(time.minute()).arg(time.second()).arg(date.year()).arg(date.month()).arg(date.day()));

    qreal h = remainHours;
    date = date.addDays(1);
    if (startPosition >= h) {
        int ret = (startPosition - h) / 24;
        h += ret * 24;
        date = date.addDays(ret);
    }
    h += 24;
    date = date.addDays(1);
    while (h - 24 >= startPosition) {
        h -= 24;
        date = date.addDays(-1);
    }
    double previous = -100;
    for ( ; ; ) {
        int x = qRound(log((h - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        QDate preDate(date);
        preDate = preDate.addDays(-1);
        int preH = h - 24;
        int preX = qRound(log((preH - startPosition) * (exp(0.1) - 1) / 6 + 1) * 300 / ratio);
        //qDebug() << preX << ' ' << log((preH - startPosition) / ratio / 6 * (exp(0.1) - 1) + 1) * 300 << endl;
        if (x <= gls::TIMER_SHAFT_LENGTH - 10 && x - previous >= gls::TIMER_SHAFT_DELTA) {
            painter->drawLine(x, 0, x, 5);
            painter->setPen(Qt::red);
            painter->drawText(QPointF(x - 10, 15), QString("%1.%2").arg(date.month()).arg(date.day()));
            painter->setPen(Qt::black);
            previous = x;
        }
        if (x <= gls::TIMER_SHAFT_LENGTH - 10 || preX <= gls::TIMER_SHAFT_LENGTH - 10)
            subDraw(painter, startPosition, ratio, h, preX, x, 0, 24);
        if (x > gls::TIMER_SHAFT_LENGTH - 10) break;
        date = date.addDays(1);
        h += 24;
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
    startPosition -= delta.x() * ratio / 2;
    if (startPosition < 0) startPosition = 0;
    update();
    QGraphicsItem::mouseMoveEvent(event);
}
void TimeShaftItem::mactransform(int delta)
{
    // This is to support mac touchpad
    startPosition -= delta * ratio / 2;
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
    if (ratio < 0.003) ratio = 0.003;
    startPosition += (exp(pre_ratio * cursor_x / 300) - exp(ratio * cursor_x / 300)) / (exp(0.1) - 1) * 6;
    if (startPosition < 0) startPosition = 0;
    update();
}
