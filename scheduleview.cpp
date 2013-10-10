#include "scheduleview.h"
#include "timeshaftitem.h"
#include <QDebug>
#include <QWheelEvent>
#include <QTimer>

ScheduleView::ScheduleView(QWidget *parent) :
    QGraphicsView(parent)
{
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
    scene->addItem(timeShaft);
    timeShaft->setPos(0, 70);

    /* Set up timer */
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this->scene, SLOT(update()));
    timer->start(1000);
}
void ScheduleView::wheelEvent(QWheelEvent *event)
{
    QPoint delta = event->pixelDelta();
    if (delta.x() != 0) timeShaft->mactransform(delta.x());
    if (delta.y() != 0) timeShaft->zoom(delta.y(), mapToScene(event->pos()));
}
