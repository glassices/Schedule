#ifndef SCHEDULEVIEW_H
#define SCHEDULEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class TimeShaftItem;
class TaskItem;
class ScheduleView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ScheduleView(QWidget *parent = 0);

signals:

public slots:

protected:
    void wheelEvent(QWheelEvent *event);
private:
    QGraphicsScene *scene;
    TimeShaftItem *timeShaft;
    TaskItem *taskItem;
};

#endif // SCHEDULEVIEW_H
