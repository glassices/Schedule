#ifndef SCHEDULEVIEW_H
#define SCHEDULEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "sdk.h"

class TimeShaftItem;
class TaskItem;

class ScheduleView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ScheduleView(QWidget *parent = 0);
    void insertTask(QString name, QDateTime dt);

signals:

public slots:

protected:
    void wheelEvent(QWheelEvent *);
    void timerEvent(QTimerEvent *);
private:
    int refreshTimerId;
    QGraphicsScene *scene;
    TimeShaftItem *timeShaft;
    TaskItem *taskItem;
    QList<gls::Record> *items;

    void refreshItemPosition();
};

#endif // SCHEDULEVIEW_H
