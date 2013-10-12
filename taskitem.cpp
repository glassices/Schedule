#include "taskitem.h"
#include "sdk.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QTime>
#include <QDate>

TaskItem::TaskItem(ScheduleView* scheduleView):
    graph(scheduleView)
{
    setFlag(ItemIsSelectable);
    setFlag(ItemIsMovable);
    setZValue(-1);
}
QRectF boundingRect() const
{
    qreal adjust=2;
    return QRectF(-wang::TASK_ITEM_WIDTH / 2 - adjust, -wang::TASK_ITEM_HEIGHT / 2 - adjust, wang::TASK_ITEM_WIDTH + adjust * 2, wang::TASK_ITEM_HEIGHT + adjust * 2);

}
 void TaskItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(option);
     Q_UNUSED(widget);
     painter->setPen(Qt::black);
     painter->setBrush(Qt::NoBrush);
     QFont font = painter->font();
     font.setWeight(0);
     font.setPointSize(10);
     painter->setFont(font);
     painter->drawText(QPointF(-10,0),QString("the first task"));
     painter->drawRect(QRectF(-TASK_ITEM_WIDTH/2,-TASK_ITEM_HEIGHT/2,TASK_ITEM_WIDTH/2,TASK_ITEM_HEIGHT/2));
 }
QPainterPath TaskItem::shape() const
{
    QPainterPath path;
    path.addRect(-wang::TASK_ITEM_WIDTH / 2, -wang::TASK_ITEM_HEIGHT / 2, wang::TASK_ITEM_WIDTH, wang::TASK_ITEM_HEIGHT);
    return path;

}
