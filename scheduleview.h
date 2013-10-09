#ifndef SCHEDULEVIEW_H
#define SCHEDULEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class TimeShaftItem;

class ScheduleView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ScheduleView(QWidget *parent = 0);

signals:

public slots:

private:
    QGraphicsScene *scene;
    TimeShaftItem *timeShaft;
};

#endif // SCHEDULEVIEW_H
