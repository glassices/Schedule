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
<<<<<<< HEAD
=======
    width = info.length() * 15;
>>>>>>> origin/Glassices
}
QRectF TaskItem::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-width / 2 - adjust, -height / 2 - adjust, width + adjust * 2, height + adjust * 2);

}
 void TaskItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(option);
     Q_UNUSED(widget);
     painter->setPen(Qt::white);
     QFont font = painter->font();
     font.setWeight(1);
     font.setFamily("Helvetica");
     font.setPointSize(15);
     width=info.length()*font.pointSize();
     height=font.pointSize()*1.5;
     painter->setFont(font);
     painter->setBrush(Qt::blue);
     painter->setRenderHint(QPainter::Antialiasing, true);
     painter->drawRect(QRectF(-width/2,-height/2,width/2,height/2));
     painter->setBrush(Qt::NoBrush);
     painter->drawText(QPointF(-width/2,0),info);
 }
QPainterPath TaskItem::shape() const
{
    QPainterPath path;
    path.addRect(-width/ 2, -height / 2, width, height/2);
    return path;

}
