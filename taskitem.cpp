#include "taskitem.h"
#include "sdk.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QDateTime>
#include <QTime>
#include <QDate>

TaskItem::TaskItem(ScheduleView* scheduleView, QString message, QDateTime dt):
    graph(scheduleView), info(message), datetime(dt)
{
    setFlag(ItemIsSelectable);
    setFlag(ItemIsMovable);
    setZValue(-1);
    width = info.length() * 15;
}
QRectF TaskItem::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-width / 2 - adjust, -wang::TASK_ITEM_HEIGHT / 2 - adjust, width + adjust * 2, wang::TASK_ITEM_HEIGHT + adjust * 2);

}
 void TaskItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(option);
     Q_UNUSED(widget);
     painter->setPen(Qt::black);
     painter->setBrush(Qt::NoBrush);
     QFont font = painter->font();
     font.setWeight(5);
     font.setPointSize(10);
     painter->setFont(font);
     painter->drawText(QPointF(-width/2,0),info);
     painter->drawRect(QRectF(-width/2,-wang::TASK_ITEM_HEIGHT/2,width/2,wang::TASK_ITEM_HEIGHT/2));
 }
QPainterPath TaskItem::shape() const
{
    QPainterPath path;
    path.addRect(-width/ 2, -wang::TASK_ITEM_HEIGHT / 2, width, wang::TASK_ITEM_HEIGHT);
    return path;

}
