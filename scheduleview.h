#ifndef SCHEDULEVIEW_H
#define SCHEDULEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class ScheduleView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ScheduleView(QWidget *parent = 0);

signals:

public slots:

private:
    QGraphicsScene *scene;
};

#endif // SCHEDULEVIEW_H
