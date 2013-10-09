#include "timebarwidget.h"
#include "scheduleview.h"
#include <QPalette>

TimeBarWidget::TimeBarWidget(QWidget *parent) :
    QWidget(parent)
{
    schedule = new ScheduleView(this);
}
