#ifndef TIMEBARWIDGET_H
#define TIMEBARWIDGET_H

#include <QWidget>

class ScheduleView;

class TimeBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimeBarWidget(QWidget *parent = 0);
private:
    ScheduleView *schedule;
};

#endif // TIMEBARWIDGET_H
