#include "scheduleview.h"
#include "timeshaftitem.h"

ScheduleView::ScheduleView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    // This is for test
    scene->setSceneRect(-300, -100, 600, 200);
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
    timeShaft->setPos(0, 0);
}
