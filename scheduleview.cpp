#include "scheduleview.h"
#include "timebarwidget.h"
#include "timeshaftitem.h"
#include "taskitem.h"
#include <QDebug>
#include <QWheelEvent>
#include <QTimer>
#include <QDatetime>
#include <QList>

ScheduleView::ScheduleView(QWidget *parent) :
    QGraphicsView(parent)
{
    items = ((TimeBarWidget *)parent)->showItems();
    qDebug() << "hehe" << items->size() << endl;
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    // This is for test
    scene->setSceneRect(-400, -100, 800, 200);
    /* Start setting parameters */
    setScene(scene);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    // Not for timer shaft rending
    //setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    /* End */

    timeShaft = new TimeShaftItem(this);
    //taskItem = new TaskItem(this,"wangwangwang");
    //scene->addItem(taskItem);
    //taskItem->setPos(100,-50);
    scene->addItem(timeShaft);
    timeShaft->setPos(0, 70);
    qDebug() << scene->items().size() << endl;

    /* Here we put all items into the scene */
    QDateTime currentDateTime = QDateTime::currentDateTime();

    qDebug() << items->size() << endl;
    for (int i = 0; i < items->size(); i++) {
        qDebug() << i << ' ';
        qDebug() << items->at(i).itemName << endl;
    }
    for (int i = 0; i < items->size(); i++)
        if (items->at(i).dateTime > currentDateTime) {
            TaskItem *taskItem = new TaskItem(this, items->at(i).itemName, items->at(i).dateTime);
            scene->addItem(taskItem);
            taskItem->setPos(0, 0);

        }
    //qDebug() << scene->items().size() << endl;
    /* Here we put all items into the scene */

    /* Set up timer */
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this->scene, SLOT(update()));
    timer->start(1000);

    refreshTimerId = startTimer(1000 / 10);
    qDebug() << 2 << endl;
}
void ScheduleView::wheelEvent(QWheelEvent *event)
{
    QPoint delta = event->pixelDelta();
    if (delta.x() != 0) timeShaft->mactransform(delta.x());
    if (delta.y() != 0) timeShaft->zoom(delta.y(), mapToScene(event->pos()));
}
void ScheduleView::insertTask(QString name, QDateTime dt)
{
    taskItem = new TaskItem(this, name, dt);
    scene->addItem(taskItem);
    taskItem->setPos(100, -50);
}
void ScheduleView::refreshItemPosition()
{
    //qDebug() << items().size() << endl;
}
void ScheduleView::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == refreshTimerId) {
        //qDebug() << scene->items.size() << endl;
        //for (int i = 0; i < items->size(); i++)
        //    qDebug() << items->at(i).dateTime << ' ';
        //qDebug() << endl;

        TaskItem tmp;
        foreach (QGraphicsItem *item, scene->items())
            if (item->type() == tmp.type()) {
                //qDebug() << ((TaskItem *)item)->seeTime() << endl;
                if (((TaskItem *)item)->seeTime() < QDateTime::currentDateTime()) {
                    scene->removeItem(item);
                    continue;
                }
                QDateTime cur = QDateTime::currentDateTime(), now = ((TaskItem *)item)->seeTime();
                int curPosition = TimeShaftItem::calcPosition((qreal)(cur.secsTo(now)) / 60 / 60);
                qDebug() << curPosition << ' ' << now << ' ' << gls::TIMER_SHAFT_LENGTH << ' ' << curPosition << endl;
                //qDebug() << gls::TIMER_SHAFT_LENGTH << endl;
                if (curPosition >= 0 && curPosition <= gls::TIMER_SHAFT_LENGTH - 10) {
                    item->show();
                    //QPointF hehe = timeShaft->mapToScene(QPointF(curPosition-1000, 0));
                    //qDebug() << hehe.x() << ' ' << hehe.y() << endl;
                    item->setPos(timeShaft->mapToScene(QPointF(curPosition-gls::TIMER_SHAFT_LENGTH/2+((TaskItem *)item)->seeWidth()/2, 0)));
                    //item->setPos(0, 0);
                }
                else item->hide();
                //qDebug() << 1 << ' ' << 2 << endl;
            }

        /*

        QList<Node *> nodes;
        foreach (QGraphicsItem *item, scene()->items()) {
            if (Node *node = qgraphicsitem_cast<Node *>(item))
                nodes << node;
        }

        foreach (Node *node, nodes)
            node->calculateForces();

        bool itemsMoved = false;
        foreach (Node *node, nodes) {
            if (node->advance())
                itemsMoved = true;
        }

        if (!itemsMoved) {
            killTimer(timerId);
            timerId = 0;
        }
        */

    }
}
